class Solution {
public:
bool fun(vector<int>& nums,int i,int n,vector<int> &dp)
{
    if(i >= n-1) return true;
    if(dp[i]!=-1) return dp[i];
    for(int jump = 1;jump<=nums[i];jump++)
    {
      if(fun(nums,i+jump,n,dp)) return dp[i] = true;
    }
    return dp[i] = false;
}
    bool canJump(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n,-1);
       return fun(nums,0,n,dp);
     
    }
};