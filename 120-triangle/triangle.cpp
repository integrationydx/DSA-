class Solution {
public:
int fun(int i,int j,vector<vector<int>>& triangle, vector<vector<int>> &dp)
{
   if(i == triangle.size() -1) return triangle[i][j];
   if(dp[i][j]!= INT_MAX) return dp[i][j];

  
    int m2 = fun(i+1,j,triangle,dp);
   int m1 = fun(i+1,j+1,triangle,dp);
  

   return dp[i][j] = triangle[i][j] + min(m1,m2);
}

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
      vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
      return fun(0,0,triangle,dp);

    }
};