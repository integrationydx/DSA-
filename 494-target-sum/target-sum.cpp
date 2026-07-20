class Solution {
public:
int fun(vector<int>& nums,int i,int sum,int target,int n)
{
    if(i == n) 
    {
        if(sum == target) return 1;
        return 0;
    }
  //  if(dp[i][sum]!=-1) return dp[i][sum];
    int c1 = fun(nums,i+1,sum+nums[i],target,n);
    int c2 = fun(nums,i+1,sum-nums[i],target,n);
    return c1+c2;
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
      //  vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return fun(nums,0,sum,target,n);

    }
};