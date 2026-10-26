#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int timer = 0;
    vector<vector<int>> ans;
    vector<vector<int>> adj;
    vector<int> tin, low;

    void dfs(int u, int p = -1) {
        tin[u] = low[u] = timer++;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    ans.push_back({u, v});
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        timer = 0;
        ans.clear();
        adj.assign(n, vector<int>());
        tin.assign(n, -1);
        low.assign(n, -1);

        for (auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (tin[i] == -1) dfs(i);
        }

        return ans;
    }
};