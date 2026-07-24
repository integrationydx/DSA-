class Solution {
public:
int fun(int i,vector<int> &nums,vector<vector<int>> &dp,int prev,int n)
{
    if(i == n) return 0;
    if(dp[i][prev+1]!= -1) return dp[i][prev+1];
      if(prev == -1 || nums[i]>nums[prev])
      {
        int c1 = 1 + fun(i+1,nums,dp,i,n);
        int c2 = fun(i+1,nums,dp,prev,n);
        return dp[i][prev+1] = max(c1,c2);
      }
      return dp[i][prev+1] = fun(i+1,nums,dp,prev,n);
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(0,nums,dp,-1,n);
    }
};