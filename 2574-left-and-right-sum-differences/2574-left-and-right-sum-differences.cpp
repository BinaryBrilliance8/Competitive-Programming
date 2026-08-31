class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();

        int right = 0;

        // Initially everything is on the right
        for (int x : nums) {
            right += x;
        }

        int left = 0;

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            // Remove current element from right
            right -= nums[i];

            ans[i] = abs(left - right);

            // Move current element to left
            left += nums[i];
        }

        return ans;
    }
};