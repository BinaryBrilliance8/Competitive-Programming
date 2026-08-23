class Solution {
public:
    int helper(vector<int> &nums, int k) {
        int left = 0, right = 0, n = nums.size(), cnt = 0;
        map<int, int> mpp;
        while (right < n) {
            mpp[nums[right]]++;
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }   
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};