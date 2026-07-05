class Solution {
public:
    int getRange(int x) {
        int mini = 9, maxi = 0;
        while (x > 0) {
            int ld = x % 10;
            mini = min(mini, ld);
            maxi = max(maxi, ld);
            x /= 10;
        }
        return maxi - mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int sum = 0;
        int maxSum = -1;
        for (int val : nums) {
            int x = getRange(val);
            if (x == maxSum) {
                sum += val;
            } else if (x > maxSum) {
                maxSum = x;
                sum = val;
            }
        }
        return sum;
    }
};