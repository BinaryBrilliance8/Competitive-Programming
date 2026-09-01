class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for (int val:arr) mpp[val]++;
        unordered_set<int> st;
        for (pair<int,int> val:mpp) {
            if (st.find(val.second)!=st.end()) return false;
            st.insert(val.second);
        }
        return true;
    }
};