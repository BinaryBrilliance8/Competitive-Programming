class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n, 0);

        int maxCost = 0;
        for (auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
            indeg[v]++;
            maxCost = max(maxCost, c);
        }

        // Topological order of DAG
        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, c] : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }

        auto can = [&](int x) -> bool {
            const long long INF = (long long)4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                // intermediate offline node cannot be used
                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (auto &[v, c] : adj[u]) {
                    if (c < x) continue; // edge too small for current score

                    // intermediate offline node cannot be used
                    if (v != n - 1 && !online[v]) continue;

                    dist[v] = min(dist[v], dist[u] + (long long)c);
                }
            }

            return dist[n - 1] <= k;
        };

        int lo = 0, hi = maxCost, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;   // try bigger minimum edge
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};