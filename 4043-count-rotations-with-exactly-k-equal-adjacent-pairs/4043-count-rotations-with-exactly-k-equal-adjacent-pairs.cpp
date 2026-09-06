class Solution {
public:
    int countRotations(string s, int k) {
        int res = 0, n = s.size();
        for (int i=0; i<n; i++) {
            int cnt = 0;
            for (int j=1; j<(int)s.size(); j++) {
                if (s[j] == s[j-1]) cnt++;
            }
            if (cnt == k) res++;
            char ch = s[0];
            for (int j=0; j<(int)s.size() - 1; j++) {
                s[j] = s[j + 1];
            }
            s.back() = ch;
        }
        return res;
    }
};