class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dp(m, 0);  // FIXED
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int prev = 0;  // reset per row

            for (int j = 0; j < m; j++) {
                int temp = dp[j]; // store old dp[j] (top)

                if (matrix[i][j] == '0') {
                    dp[j] = 0;
                }
                else if (i == 0 || j == 0) {
                    dp[j] = 1;
                }
                else {
                    dp[j] = min({prev, dp[j], dp[j-1]}) + 1;
                }

                maxi = max(maxi, dp[j]);
                prev = temp; // update diagonal
            }
        }

        return maxi * maxi;
    }
};