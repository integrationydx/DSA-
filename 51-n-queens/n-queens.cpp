class Solution {
public:
    bool safe(vector<string> &board, int row, int col, int n)
{
    for(int j = 0; j < n; j++)
    {
        if(board[row][j] == 'Q')
            return false;
    }

    for(int i = 0; i < n; i++)
    {
        if(board[i][col] == 'Q')
            return false;
    }

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 'Q')
            return false;
    }

    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 'Q')
            return false;
    }

    
    for(int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if(board[i][j] == 'Q')
            return false;
    }

  
    for(int i = row, j = col; i < n && j < n; i++, j++)
    {
        if(board[i][j] == 'Q')
            return false;
    }

    return true;
}


void fun(vector<string> &ans,vector<vector<string>> &ds,int i,int j,int n,int queens)
{
     if(queens == n)
   {
    ds.push_back(ans);
    return;
   }
   if(i == n) return;
  

   int ni = i;
   int nj = j + 1;

   if (nj == n)
    {
        ni++;
        nj = 0;
    }

fun(ans, ds, ni, nj, n, queens);

if (safe(ans, i, j, n))
{
    ans[i][j] = 'Q';

    fun(ans, ds, ni, nj, n, queens + 1);

    ans[i][j] = '.';
}
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>ans(n,string(n,'.'));
        vector<vector<string>>ds;
        int queens;
         fun(ans,ds,0,0,n,0);
         return ds;
    }
};