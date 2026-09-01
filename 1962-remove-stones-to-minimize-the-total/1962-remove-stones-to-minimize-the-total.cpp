class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int val:piles) pq.push(val);
        while (k--) {
            int ele = pq.top(); pq.pop();
            ele -= ele / 2;
            pq.push(ele);
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;

    }
};