class Solution {
public:
int fun(string &str1, string &str2,int i,int j,int n,int m,vector<vector<int>> &dp)
{
    if(i == n || j == m) return 0;
    if(dp[i][j]!= -1) return dp[i][j];

    if(str1[i] == str2[j])
    {
        return dp[i][j] = 1+ fun(str1,str2,i+1,j+1,n,m,dp);
    }
    int c1 = fun(str1,str2,i+1,j,n,m,dp);
    int c2 = fun(str1,str2,i,j+1,n,m,dp);

    return dp[i][j] =  max(c1,c2);

}
    string shortestCommonSupersequence(string str1, string str2) {
        string res = "";
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
         fun(str1,str2,0,0,n,m,dp);
         int i = 0;
         int j =0;
         while(i<n && j<m)
{
    if(str1[i] == str2[j])
    {
        res += str1[i];
        i++;
        j++;
    }
    else if(dp[i+1][j] >= dp[i][j+1])
    {
        res += str1[i];
        i++;
    }
    else
    {
        res += str2[j];
        j++;
    }
}

while(i<n) res += str1[i++];
while(j<m) res += str2[j++];
      
         return res;
    }
};