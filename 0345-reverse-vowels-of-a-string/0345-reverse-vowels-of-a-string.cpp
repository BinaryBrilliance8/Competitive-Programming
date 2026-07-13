class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i';
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) i++;
            while (i < j && !isVowel(s[j])) j--;

            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};