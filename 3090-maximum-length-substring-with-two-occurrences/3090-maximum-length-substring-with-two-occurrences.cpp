class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0, right = 0, n = s.size();
        int freq[26] = {0}, ans = 0;
        while (right < n) {
            freq[s[right] - 'a']++;
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};