class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int cur = 0;

        for (char c : s) {
            int next = c - '0';
            int diff = abs(cur - next);

            ans += min(diff, 10 - diff);
            cur = next;
        }

        return ans;
    }
};