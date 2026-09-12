class Solution {
public:

    struct State {
        long long score = 0;
        vector<int> ids;
    };

    State better(const State& a, const State& b) {
        if (a.score != b.score)
            return (a.score > b.score ? a : b);

        if (a.ids != b.ids)
            return (lexicographical_compare(
                a.ids.begin(), a.ids.end(),
                b.ids.begin(), b.ids.end()
            ) ? a : b);

        return a;
    }

    vector<int> maximumWeight(
        vector<vector<int>>& intervals
    ) {
        int n = intervals.size();

        // {left, right, weight, original_index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by left endpoint
        sort(a.begin(), a.end());

        // left[i] = left endpoint of interval i
        vector<int> left(n);

        for (int i = 0; i < n; i++)
            left[i] = a[i][0];

        // next[i] = first interval j such that
        // left[j] > right[i]
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                left.begin(),
                left.end(),
                a[i][1]
            ) - left.begin();
        }

        // dp[i][k]:
        // best answer using intervals [i ... n-1]
        // with at most k intervals
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip interval i
                State skip = dp[i + 1][k];

                // Option 2: take interval i
                State take = dp[nxt[i]][k - 1];

                take.score += a[i][2];

                take.ids.push_back(a[i][3]);

                // IDs need to be sorted for lexicographical comparison.
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].ids;
    }
};