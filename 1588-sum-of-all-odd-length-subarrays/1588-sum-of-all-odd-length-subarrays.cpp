class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int n = arr.size();

        vector<int> prefix(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        int ans = 0;

        // Choose starting point
        for (int l = 0; l < n; l++) {

            // Choose ending point
            for (int r = l; r < n; r++) {

                int length = r - l + 1;

                // Only odd length
                if (length % 2 == 1) {

                    int sum = prefix[r + 1] - prefix[l];

                    ans += sum;
                }
            }
        }

        return ans;
    }
};