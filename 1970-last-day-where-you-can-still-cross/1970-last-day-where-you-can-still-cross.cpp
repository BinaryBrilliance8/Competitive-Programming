class Solution {
public:
    int ROW;
    int COL;

    vector<vector<int>> directions{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    bool dfs(vector<vector<int>>& grid, int i, int j) {

        // Out of bounds OR blocked
        if (i < 0 || i >= ROW || j < 0 || j >= COL || grid[i][j] == 1) {
            return false;
        }

        // Reached bottom row
        if (i == ROW - 1) {
            return true;
        }

        // Mark visited
        grid[i][j] = 1;

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (dfs(grid, new_i, new_j)) {
                return true;
            }
        }

        return false;
    }

    bool canCross(int mid, vector<vector<int>>& cells) {

        vector<vector<int>> grid(ROW, vector<int>(COL));

        // Flood cells from day 1 to day mid+1
        for (int i = 0; i <= mid; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;

            grid[x][y] = 1;
        }

        // Try starting from every cell in top row
        for (int j = 0; j < COL; j++) {
            if (grid[0][j] == 0 && dfs(grid, 0, j)) {
                return true;
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        ROW = row;
        COL = col;

        int n = cells.size();

        int low = 0;
        int high = n - 1;

        int lastDay = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canCross(mid, cells)) {
                // Can still cross
                lastDay = mid + 1;
                low = mid + 1;
            }
            else {
                // Cannot cross anymore
                high = mid - 1;
            }
        }

        return lastDay;
    }
};