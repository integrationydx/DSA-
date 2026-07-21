class Solution {
public:

int fun(string &s,int i,int j,int n,vector<vector<int>> &dp)
{
   
    if(i == j) return 1;
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i] == s[j])
    {
        return dp[i][j] = 2+ fun(s,i+1,j-1,n,dp);
    }
    int c1 = fun(s,i+1,j,n,dp);
    int c2 = fun(s,i,j-1,n,dp);

    return dp[i][j] = max(c1,c2);

}
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(s,0,n-1,n,dp);
    }
};