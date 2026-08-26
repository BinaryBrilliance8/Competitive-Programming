class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int k = s1.size();

        if (k > s2.size())
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // Frequency of s1
        for (char c : s1) {
            need[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {

            // Add right
            window[s2[right] - 'a']++;

            // Window size = k
            if (right - left + 1 == k) {

                // Check if frequencies match
                if (window == need)
                    return true;

                // Remove left
                window[s2[left] - 'a']--;
                left++;
            }
        }

        return false;
    }
};