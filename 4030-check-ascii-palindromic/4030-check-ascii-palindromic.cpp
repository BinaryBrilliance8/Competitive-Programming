class Solution {
public:
    bool isPalindromic(string s) {
        string bits;
        for (char ch:s) {
            int x = (int)ch;
            for (int i=7; i>=0; i--) {
                bits += ((x >> i) & 1) + '0';
            }
        }
        int l=0, r=bits.size() - 1;
        while (l < r) {
            if (bits[l] != bits[r]) return false;
            l++; r--;
        }
        return true;
    }
};