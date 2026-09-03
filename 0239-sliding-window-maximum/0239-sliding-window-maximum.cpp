class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();

        // Build first window
        for (int i = 0; i < k; i++) {

            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
        }

        // Maximum of first window
        ans.push_back(nums[dq.front()]);

        // Process remaining windows
        for (int i = k; i < n; i++) {

            // Remove smaller elements
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Remove expired index
            if (dq.front() <= i - k)
                dq.pop_front();

            // Maximum of current window
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};