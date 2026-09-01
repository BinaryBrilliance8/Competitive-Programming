class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int k = 0; k < n - 2; k++) {

            int i = k + 1;
            int j = n - 1;

            while (i < j) {

                int sum = nums[k] + nums[i] + nums[j];

                // Is this sum closer to target?
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                // Need a bigger sum
                if (sum < target) {
                    i++;
                }
                // Need a smaller sum
                else {
                    j--;
                }
            }
        }

        return closestSum;
    }
};