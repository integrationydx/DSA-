class Solution {
public:
    int x[8] = {-1,-1,-1,0,0,1,1,1};
    int y[8] = {-1,0,1,-1,1,-1,0,1};

    bool isValid(int row, int col, int n, int m)
    {
        return (row >= 0 && row < n &&
                col >= 0 && col < m);
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int cnt = 0;
                for(int k = 0; k < 8; k++)
                {
                    int nr = i + x[k];
                    int nc = j + y[k];

                    if(isValid(nr, nc, n, m) && board[nr][nc] == 1)
                    {
                        cnt++;
                    }
                }

                if(board[i][j] == 1)
                {
                    if(cnt < 2)
                        temp[i][j] = 0;
                    else if(cnt == 2 || cnt == 3)
                        temp[i][j] = 1;
                    else
                        temp[i][j] = 0;
                }
                else
                {
                    if(cnt == 3)
                        temp[i][j] = 1;
                    else
                        temp[i][j] = 0;
                }
            }
        }

        board = temp;
    }
};