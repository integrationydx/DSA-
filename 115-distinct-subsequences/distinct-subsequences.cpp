class Solution {
public:
int fun(string &s,string &t,int n,int m,int i,int j,vector<vector<int>>&dp)
{
     if(j == m) return 1;
    if(i == n ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i] == t[j])
    {
        int c1 = fun(s,t,n,m,i+1,j+1,dp);
        int c2 = fun(s,t,n,m,i+1,j,dp);
        return dp[i][j] = c1+c2;
    }
    return dp[i][j] =  fun(s,t,n,m,i+1,j,dp);
}
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(s,t,n,m,0,0,dp);
    }
};