class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - i;

            int count = (left * right + 1) / 2;

            ans += arr[i] * count;
        }

        return ans;
    }
};