class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = -1;
        
        // The cost function is piecewise linear and convex.
        // Its minimum must occur at one of the critical boundary points 
        // where the requirement for either need1 or need2 (or both) is exactly met by the 'costBoth' items, or 0.
        long long critical_points[] = {0LL, (long long)need1, (long long)need2, (long long)max(need1, need2)};
        
        for (long long x : critical_points) {
            long long rem1 = max(0LL, need1 - x);
            long long rem2 = max(0LL, need2 - x);
            
            long long current_cost = x * costBoth + rem1 * cost1 + rem2 * cost2;
            if (ans == -1 || current_cost < ans) {
                ans = current_cost;
            }
        }
        
        return ans;
    }
};