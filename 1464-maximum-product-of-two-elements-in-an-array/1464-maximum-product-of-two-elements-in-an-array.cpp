class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 0, second = 0;
        for (int val:nums) {
            if (val > maxi) {
                second = maxi;
                maxi = val;
            } else if (val > second) {
                second = val;
            }
        }
        return (maxi - 1) * (second - 1);
    }
};