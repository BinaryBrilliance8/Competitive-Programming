class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            k += nums[i];
        }

        if (k == 0 || k == n) return 0;

        nums.insert(nums.end(), nums.begin(), nums.end());

        int cnt = 0;

        for (int i = 0; i < k; i++) {
            cnt += nums[i];
        }

        int res = k - cnt;

        for (int i = k; i < n + k; i++) {
            cnt += nums[i];
            cnt -= nums[i - k];

            res = min(res, k - cnt);
        }

        return res;
    }
};