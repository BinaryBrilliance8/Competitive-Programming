class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();

        if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0) return 0;

        int gold = grid[i][j];
        grid[i][j] = 0;
        int best = 0;
        best = max(best, dfs(i+1, j, grid));
        best = max(best, dfs(i-1, j, grid));
        best = max(best, dfs(i, j-1, grid));
        best = max(best, dfs(i, j+1, grid));

        grid[i][j] = gold;

        return best + gold;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] != 0) ans = max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }
};