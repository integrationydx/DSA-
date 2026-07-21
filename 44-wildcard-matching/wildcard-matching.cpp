class Solution {
public:
bool fun(string &s,string &p,int n,int m,int i,int j,vector<vector<int>> &dp)
{
    if(i == n && j == m)
    return true;
    if(j == m) return false;
    if(i == n) 
{
    while(j < m)
    {
        if(p[j] != '*')
            return false;
        j++;
    }
    return true;
}
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i] == p[j])
    {
        return dp[i][j] = fun(s,p,n,m,i+1,j+1,dp);
    }
    if(p[j] == '?')
    {
        return dp[i][j]= fun(s,p,n,m,i+1,j+1,dp);
      
    }
    if(p[j] == '*')
    {
        int c1 = fun(s,p,n,m,i+1,j,dp);
        int c2 = fun(s,p,n,m,i,j+1,dp);
        return dp[i][j] =  c1 || c2;
    }

    return 0;


}
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(s,p,n,m,0,0,dp);
    }
};