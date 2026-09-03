class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int freq[51] = {};

        // First window
        for (int i = 0; i < k; i++) {
            if (nums[i] < 0)
                freq[-nums[i]]++;
        }

        // Every window
        for (int i = k; i <= nums.size(); i++) {

            int count = 0;
            int beauty = 0;

            // Find x-th smallest negative
            for (int v = 50; v >= 1; v--) {
                count += freq[v];

                if (count >= x) {
                    beauty = -v;
                    break;
                }
            }

            ans.push_back(beauty);

            // If no more windows, stop
            if (i == nums.size())
                break;

            // Remove outgoing element
            if (nums[i - k] < 0)
                freq[-nums[i - k]]--;

            // Add incoming element
            if (nums[i] < 0)
                freq[-nums[i]]++;
        }

        return ans;
    }
};