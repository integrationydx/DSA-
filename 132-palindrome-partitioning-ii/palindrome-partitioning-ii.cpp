class Solution {
public:
bool pal(string &s,int i, int k)
{
  
   
    while(i<k)
    {
        if(s[i] == s[k])
        {
            i++;
            k--;
        }
        else{
            return false;
        }
    }
    return true;
}
int fun(string &s,int i,int n,vector<int> &dp)
{
   if(i == n) return 0;
   if(dp[i]!=-1) return dp[i];
   int ans = INT_MAX;
   for(int k=i;k<=n;k++)
   {
    if(pal(s,i,k))
    {
        ans =  min(ans,1+fun(s,k+1,n,dp));
    }


   }
    return  dp[i] = ans;
}
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return fun(s,0,n,dp)-1;
    }
};