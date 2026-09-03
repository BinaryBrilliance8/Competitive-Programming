class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long> lo, hi;
        auto balance = [&]() {
            if (lo.size() > hi.size() + 1) {
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }
            if (hi.size() > lo.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
        };

        vector<double> ans;

        for (int i=0; i<(int)nums.size(); i++) {
            if (lo.empty() || nums[i] <= *lo.rbegin()) lo.insert(nums[i]);
            else hi.insert(nums[i]);
            balance();

            if (i >= k) {
                long long out = nums[i-k];
                if (out <= *lo.rbegin()) lo.erase(lo.find(out));
                else hi.erase(hi.find(out));
                balance();
            }
            if (i >= k-1) {
                if (k % 2 == 1) ans.push_back(*lo.rbegin());
                else ans.push_back(((double) *lo.rbegin() + (double) *hi.begin()) / 2.0);
            }
        }
        return ans;
    }
};