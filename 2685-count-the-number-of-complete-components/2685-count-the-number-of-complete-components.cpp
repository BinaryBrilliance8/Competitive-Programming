class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DisjointSet ds(n);

        // Step 1: Union all edges
        for(auto &edge : edges) {
            ds.unionBySize(edge[0], edge[1]);
        }

        // Step 2: Count vertices in each component
        vector<int> vertexCount(n, 0);

        for(int i = 0; i < n; i++) {
            int root = ds.find(i);
            vertexCount[root]++;
        }

        // Step 3: Count edges in each component
        vector<int> edgeCount(n, 0);

        for(auto &edge : edges) {
            int root = ds.find(edge[0]);
            edgeCount[root]++;
        }

        // Step 4: Check complete components
        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(ds.find(i) != i) continue;

            int vertices = vertexCount[i];
            int expectedEdges = vertices * (vertices - 1) / 2;

            if(edgeCount[i] == expectedEdges) {
                ans++;
            }
        }

        return ans;
    }
};