class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = min(minOdd, x);
            }
        }

        // No odd numbers -> already all even
        if (minOdd == INT_MAX)
            return true;

        // Every even number must be able to subtract
        // a smaller odd number.
        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd)
                return false;
        }

        return true;
    }
};