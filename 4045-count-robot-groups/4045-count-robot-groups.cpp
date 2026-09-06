class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector<int> res;
        int n = speed.size();
        for (int i=0; i<n; i++) {
            if (i > 0 && position[i] - position[i-1] <= distance) res.pop_back();
            res.push_back(speed[i]);
        }

        int minSpeed = INT_MAX, ans = 0;
        for (int i=res.size()-1; i>=0; i--) {
            if (res[i] <= minSpeed) {
                ans++;
                minSpeed = res[i];
            }
        }
        return ans;
    }
};