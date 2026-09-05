class Solution {
public:
    int n;
    int dp[50001];

    int getNextIndex(vector<vector<int>>& arr, int l, int end) {
        int r = n - 1;
        int res = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid][0] >= end) {
                res = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }

        return res;
    }

    int solve(vector<vector<int>>& arr, int i) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int next = getNextIndex(arr, i + 1, arr[i][1]);

        int take = arr[i][2] + solve(arr, next);

        int notTake = solve(arr, i + 1);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        n = startTime.size();

        memset(dp, -1, sizeof(dp));

        vector<vector<int>> arr(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end(),
             [](const auto& a, const auto& b) {
                 return a[0] < b[0];
             });

        return solve(arr, 0);
    }
};