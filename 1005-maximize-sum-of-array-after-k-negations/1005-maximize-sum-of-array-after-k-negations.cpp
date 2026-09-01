class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        // turn negative into positive
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        // if odd flips remain, flip smallest
        if (k % 2) {
            int mn = *min_element(nums.begin(), nums.end());

            for (int &val : nums) {
                if (val == mn) {
                    val = -val;
                    break;
                }
            }
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};