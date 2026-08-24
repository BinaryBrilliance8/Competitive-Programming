class Solution {
private:

    void dfs(int row,
             int col,
             vector<vector<char>>& board,
             vector<vector<int>>& vis)
    {
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++)
        {
            int nrow = row + dx[k];
            int ncol = col + dy[k];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               board[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

public:

    void solve(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // First column
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O' && !vis[i][0])
            {
                dfs(i, 0, board, vis);
            }
        }

        // Last column
        for(int i = 0; i < n; i++)
        {
            if(board[i][m - 1] == 'O' && !vis[i][m - 1])
            {
                dfs(i, m - 1, board, vis);
            }
        }

        // First row
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O' && !vis[0][j])
            {
                dfs(0, j, board, vis);
            }
        }

        // Last row
        for(int j = 0; j < m; j++)
        {
            if(board[n - 1][j] == 'O' && !vis[n - 1][j])
            {
                dfs(n - 1, j, board, vis);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};