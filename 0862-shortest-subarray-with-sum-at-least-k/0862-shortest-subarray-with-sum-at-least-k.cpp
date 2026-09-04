class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> pref(n + 1, 0);
        for (int i=0; i<n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        int ans = n + 1;
        deque<int> dq;
        for (int j=0; j<=n; j++) {
            while (dq.size() && pref[j] - pref[dq.front()] >= k) {
                ans = min(ans, j-dq.front());
                dq.pop_front();
            }
            while (dq.size() && pref[j] <= pref[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);
        }
        return ans == n + 1?-1:ans;
    }
};