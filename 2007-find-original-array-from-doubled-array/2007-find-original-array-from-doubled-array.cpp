class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n & 1) return {};
        sort(changed.begin(), changed.end());
        vector<int> res;
        unordered_map<int,int> mpp;
        for (int val:changed) {
            mpp[val]++;
        }
        for(int i=0; i<n; i++) {
            if (mpp[changed[i]] == 0) continue;
            if (mpp[changed[i]*2] == 0) return {};
            res.push_back(changed[i]);
            mpp[changed[i]]--;
            mpp[changed[i] * 2]--;
        }
        return res;
    }
};