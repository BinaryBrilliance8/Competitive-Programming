class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int left = 0, right = 0;
        long long sum = 0;
        long long ans = 0;

        unordered_map<int, int> freq;

        while (right < nums.size()) {

            // Add right
            sum += nums[right];
            freq[nums[right]]++;

            // Window size = k
            if (right - left + 1 == k) {

                // Number of distinct elements == k
                if (freq.size() == k) {
                    ans = max(ans, sum);
                }

                // Remove left
                sum -= nums[left];

                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;
            }

            right++;
        }

        return ans;
    }
};