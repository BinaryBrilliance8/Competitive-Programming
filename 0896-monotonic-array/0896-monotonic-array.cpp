class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;

        for (int val = 1; val < nums.size(); val++) {
            if (nums[val] < nums[val-1]) {
                inc = false;
            }

            if (nums[val] > nums[val-1]) {
                dec = false;
            }
        }

        return inc || dec;
    }
};