class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int x=k;
        while (st.contains(x)) { x += k;}
        return x;
    }
};