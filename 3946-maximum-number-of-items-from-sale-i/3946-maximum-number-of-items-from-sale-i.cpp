class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAX_F = 1500;
        vector<int> cnt(MAX_F + 1, 0);
        int minPrice = INT_MAX;

        for (const auto& item : items) {
            cnt[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        // Precompute number of free copies granted by buying an item with factor f
        vector<int> freeCopies(MAX_F + 1, 0);
        for (int f = 1; f <= MAX_F; ++f) {
            if (cnt[f] == 0) continue;
            int totalMultiples = 0;
            for (int m = f; m <= MAX_F; m += f) {
                totalMultiples += cnt[m];
            }
            freeCopies[f] = totalMultiples - 1; // Exclude the item itself
        }

        // 0/1 Knapsack for buying at most 1 copy of each item
        vector<int> dp(budget + 1, 0);
        for (const auto& item : items) {
            int price = item[1];
            int value = 1 + freeCopies[item[0]];
            for (int w = budget; w >= price; --w) {
                dp[w] = max(dp[w], dp[w - price] + value);
            }
        }

        // Spend remaining budget on the cheapest item
        int ans = 0;
        for (int w = 0; w <= budget; ++w) {
            ans = max(ans, dp[w] + (budget - w) / minPrice);
        }

        return ans;
    }
};