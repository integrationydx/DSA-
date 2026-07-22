class Solution {
public:
int fun(vector<vector<int>>& matrix, int n,int m,int i,int j,vector<vector<int>> &dp)
{
    if(i >= n || j >= m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = fun(matrix, n,m,i, j + 1, dp);
        int down = fun(matrix,n,m, i + 1, j, dp);
        int diag = fun(matrix,n,m, i + 1, j + 1, dp);

        if(matrix[i][j] == 0)
            return dp[i][j] = 0;

        return dp[i][j] = 1 + min({right, down, diag});

}
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        ans += fun(matrix,n,m, i, j, dp);
    }
}

return ans;
    }
};