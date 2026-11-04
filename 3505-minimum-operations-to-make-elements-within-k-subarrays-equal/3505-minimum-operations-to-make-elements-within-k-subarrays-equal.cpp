
class Solution {
    class SlidingMedian {
        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;
        int x;

        void balance() {
            int need = min((x + 1) / 2,
                           (int)(lo.size() + hi.size()));

            while ((int)lo.size() > need) {
                auto it = prev(lo.end());
                int v = *it;

                lo.erase(it);
                sumLo -= v;

                hi.insert(v);
                sumHi += v;
            }

            while ((int)lo.size() < need) {
                auto it = hi.begin();
                int v = *it;

                hi.erase(it);
                sumHi -= v;

                lo.insert(v);
                sumLo += v;
            }
        }

    public:
        SlidingMedian(int x) : x(x) {}

        void add(int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }

            balance();
        }

        void remove(int v) {
            auto it = lo.find(v);

            if (it != lo.end()) {
                lo.erase(it);
                sumLo -= v;
            } else {
                it = hi.find(v);
                hi.erase(it);
                sumHi -= v;
            }

            balance();
        }

        long long getCost() {
            long long median = *lo.rbegin();

            return median * (long long)lo.size() - sumLo
                 + sumHi - median * (long long)hi.size();
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Step 1: Calculate the cost of every window of size x.
        vector<long long> cost(n - x + 1);

        SlidingMedian sm(x);

        for (int i = 0; i < n; i++) {
            sm.add(nums[i]);

            if (i >= x) {
                sm.remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = sm.getCost();
            }
        }

        // Step 2: DP to select k non-overlapping windows.
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Option 1: Skip the current element.
                curr[i] = curr[i - 1];

                // Option 2: Select a window ending at i - 1.
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
