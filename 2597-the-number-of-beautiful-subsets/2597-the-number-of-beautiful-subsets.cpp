class Solution {
public:
    int ans = 0;
    unordered_map<int, int> mpp;

    void solve(int i, vector<int>& nums, int k) {
        if (i >= nums.size()) {
            ans++;
            return;
        }

        // Don't take nums[i]
        solve(i + 1, nums, k);

        // Take nums[i] if valid
        if (mpp[nums[i] - k] == 0 &&
            mpp[nums[i] + k] == 0) {

            mpp[nums[i]]++;

            solve(i + 1, nums, k);

            mpp[nums[i]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        solve(0, nums, k);

        return ans - 1; // remove empty subset
    }
};