class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int f[51] = {};
        for (int val : nums) {
            f[val]++;
        }
        int res = -1, n = nums.size();
        for (int i=0; i<n; i++) {
            if (k == n || f[nums[i]] == 1 && (k == 1 || i == 0 || i == n-1)) {
                res = max(res, nums[i]);
            }
        }
        return res;
    }
};