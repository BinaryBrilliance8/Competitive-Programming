class Solution {
public:

    int n;

    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    bool dfs(int i, int j, int water,
             vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {

        if (i < 0 || i >= n || j < 0 || j >= n)
            return false;

        if (grid[i][j] > water)
            return false;

        if (visited[i][j])
            return false;

        if (i == n - 1 && j == n - 1)
            return true;

        visited[i][j] = true;

        for (auto& dir : directions) {

            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (dfs(new_i, new_j, water, grid, visited))
                return true;
        }

        return false;
    }

    bool canReach(int water, vector<vector<int>>& grid) {

        vector<vector<bool>> visited(
            n,
            vector<bool>(n, false)
        );

        return dfs(0, 0, water, grid, visited);
    }

    int swimInWater(vector<vector<int>>& grid) {

        n = grid.size();

        int low = 0;
        int high = n * n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canReach(mid, grid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};