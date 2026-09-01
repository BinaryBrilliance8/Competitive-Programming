class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> pq(nums.begin(), nums.end());

        long long ans = 0;

        while (k--) {

            int x = pq.top();
            pq.pop();

            ans += x;

            x = ceil(x/3.0);

            pq.push(x);
        }

        return ans;
    }
};