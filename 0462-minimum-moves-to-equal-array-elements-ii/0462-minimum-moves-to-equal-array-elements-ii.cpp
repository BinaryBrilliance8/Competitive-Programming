class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        
        int median = *mid;
        long long moves = 0;
        for (int x : nums) {
            moves += abs((long long)x - median);
        }
        return (int)moves;
    }
};