class Solution {
public:
int fun(vector<int> &f, int i,int j,int n,vector<vector<int>> &dp)
{
    if(i>j) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    int res = INT_MIN;
    for(int k=i;k<=j;k++)
    {
        int cost = f[i-1]*f[k]*f[j+1];
        int r = cost + fun(f,i,k-1,n,dp) + fun(f,k+1,j,n,dp);
        res = max(r,res);
    }
    return dp[i][j] = res;
    
}
    int maxCoins(vector<int>& nums) {
        vector<int>f;
        f.push_back(1);
        for(int i=0;i<nums.size();i++)
        {
            f.push_back(nums[i]);
        }
        f.push_back(1);
        int n = f.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(f,1,n-2,n,dp);
    }
};