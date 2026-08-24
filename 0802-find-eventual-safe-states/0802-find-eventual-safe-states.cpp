class Solution {
public:
    bool dfs(int src, vector<int> &vis, vector<vector<int>>& graph,vector<int> &path, vector<int> &check) {
        vis[src] = 1;
        path[src] = 1;
        // check[src] = 0;
        for (int val : graph[src]) {
            if (!vis[val]) {
                if (dfs(val, vis, graph, path, check)) {
                    return true;
                }
            } else {
                if (path[val]) {
                    return true;
                }
            }
        }
        check[src] = 1;
        path[src] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        vector<int> check(n, 0);
        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, graph, path, check)) {
                    
                }
            }
        }
        for (int i=0; i<n; i++) {
            if (check[i] == 1) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};