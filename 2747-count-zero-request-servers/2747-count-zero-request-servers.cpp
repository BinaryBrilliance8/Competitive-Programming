class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(q);

        int left = 0, right = 0;
        int activeServers = 0;
        int m = logs.size();

        for (auto [time, idx] : sortedQueries) {

            // Add logs with timestamp <= current query time
            while (right < m && logs[right][1] <= time) {
                int id = logs[right][0];

                if (freq[id] == 0) {
                    activeServers++;
                }

                freq[id]++;
                right++;
            }

            // Remove logs outside the inclusive window [time - x, time]
            while (left < right && logs[left][1] < time - x) {
                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0) {
                    activeServers--;
                }

                left++;
            }

            ans[idx] = n - activeServers;
        }

        return ans;
    }
};