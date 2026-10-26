class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string res;
        res.reserve(n + m);

        int i = 0, j = 0;
        while (i < n && j < m) {
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        }

        while (i < n) res.push_back(word1[i++]);
        while (j < m) res.push_back(word2[j++]);

        return res;
    }
};