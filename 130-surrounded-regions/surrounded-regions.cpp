class Solution {
public:

    bool valid(int i, int j, int n, int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        return true;
    }

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    void dfs(int i, int j, int n, int m, vector<vector<char>>& board)
    {
        board[i][j] = '#';

        for(int k = 0; k < 4; k++)
        {
            int row = i + x[k];
            int col = j + y[k];

            if(valid(row, col, n, m) && board[row][col] == 'O')
            {
                dfs(row, col, n, m, board);
            }
        }

        return;
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // first row
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O')
            {
                dfs(0, j, n, m, board);
            }
        }

        // last row
        for(int j = 0; j < m; j++)
        {
            if(board[n - 1][j] == 'O')
            {
                dfs(n - 1, j, n, m, board);
            }
        }

        // first column
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O')
            {
                dfs(i, 0, n, m, board);
            }
        }

        // last column
        for(int i = 0; i < n; i++)
        {
            if(board[i][m - 1] == 'O')
            {
                dfs(i, m - 1, n, m, board);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};