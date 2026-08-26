class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int n = nums.size();

        int left = k;
        int right = k;

        int mini = nums[k];
        int ans = nums[k];

        while (left > 0 || right < n - 1) {

            // Expand toward larger neighbor
            if (left == 0) {
                right++;
            }
            else if (right == n - 1) {
                left--;
            }
            else if (nums[left - 1] >= nums[right + 1]) {
                left--;
            }
            else {
                right++;
            }

            // Update minimum
            mini = min(mini, min(nums[left], nums[right]));

            // Calculate score
            ans = max(ans, mini * (right - left + 1));
        }

        return ans;
    }
};