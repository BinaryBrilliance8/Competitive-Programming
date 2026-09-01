class Solution {
public:

    int t[1001][1001];

    bool solve(int i, int j, string &s) {

        // 1 character or no characters
        if (i >= j)
            return true;

        // Already calculated
        if (t[i][j] != -1)
            return t[i][j];

        // First and last characters must match
        if (s[i] == s[j])
            return t[i][j] = solve(i + 1, j - 1, s);

        return t[i][j] = false;
    }

    string longestPalindrome(string s) {

        int n = s.length();

        memset(t, -1, sizeof(t));

        int maxLen = 0;
        int sp = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                if (solve(i, j, s)) {

                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};