class Solution {
public:
int fun(int i,int j,vector<vector<int>> &dp, int m,int n)
{
    if(i>=m || j>=n) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    if(i == m-1 && j == n-1) return 1;
   int  down = fun(i+1,j,dp, m, n);
   int  right = fun(i,j+1,dp, m, n);
    return dp[i][j] = down + right;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(0,0,dp,m,n);
    }
};