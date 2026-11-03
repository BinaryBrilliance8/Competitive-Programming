class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int val = nums[i - 1] == 1 ? 1 : -1;
            pre[i] = pre[i - 1] + val; 
        }
        unordered_map<int, int> mpp;
        int res = 0;
        for (int i = 0; i <= n; i++) {
            if (mpp.find(pre[i]) != mpp.end()) {
                res = max(res, i - mpp[pre[i]]);
            } else {
                mpp[pre[i]] = i;
            }
        }
        return res;
    }
};