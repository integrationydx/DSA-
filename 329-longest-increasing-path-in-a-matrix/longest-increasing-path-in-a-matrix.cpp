class Solution {
public:
bool isValid(int i, int j, int n,int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

int fun(vector<vector<int>> &matrix,vector<vector<int>> &dp,int i,int j,int n,int m)
{
  
   if(dp[i][j]!= -1) return dp[i][j];
   int ans = 1;
   for(int k=0;k<4;k++)
   {
    int row = i + x[k];
    int col = j + y[k];
    if(isValid(row,col,n,m))
    {
        if(matrix[row][col]>matrix[i][j])
        {
         ans = max(ans,1 + fun(matrix,dp,row,col,n,m));
        }
    }
   }
    dp[i][j] = ans;
    return ans;

}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            ans = max(ans,fun(matrix,dp,i,j,n,m));
        }
       }
       return ans;
    }
};