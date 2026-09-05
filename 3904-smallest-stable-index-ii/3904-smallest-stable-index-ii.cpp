class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n);
        res[0] = nums[0];
        for (int i=1; i<n; i++) {
            res[i] = max(res[i-1], nums[i]);
        }
        int mini = INT_MAX;
        for (int i=n-1; i>=0; i--) {
            mini = min(mini, nums[i]);
            res[i] -= mini;
        }
        for (int i=0; i<n; i++) {
            if (res[i] <= k) return i;
        }
        return -1;
    }
};