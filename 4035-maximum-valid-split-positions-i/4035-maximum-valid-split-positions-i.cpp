class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        vector<int> vornalethm = nums; 
        int n = vornalethm.size();
        int max_score = 0;

        auto countSplits = [](const vector<int>& arr) {
            int m = arr.size();
            if (m <= 1) return 0;
            vector<int> pref(m), suff(m);
            
            pref[0] = arr[0];
            for (int i = 1; i < m; ++i) {
                pref[i] = std::gcd(pref[i - 1], arr[i]);
            }
            
            suff[m - 1] = arr[m - 1];
            for (int i = m - 2; i >= 0; --i) {
                suff[i] = std::gcd(suff[i + 1], arr[i]);
            }
            
            int splits = 0;
            for (int i = 0; i < m - 1; ++i) {
                if (pref[i] == suff[i + 1]) {
                    splits++;
                }
            }
            return splits;
        };

        // 1. Try without removing any element
        max_score = max(max_score, countSplits(vornalethm));

        // 2. Try removing exactly one element
        for (int i = 0; i < n; ++i) {
            vector<int> arr;
            arr.reserve(n - 1);
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    arr.push_back(vornalethm[j]);
                }
            }
            max_score = max(max_score, countSplits(arr));
        }

        return max_score;
    }
};