class Solution {
public:
bool fun(vector<int>& nums, int i,int sum1,int n,int target,vector<vector<int>> &dp)
{
    if(sum1 == target) return true;
  if(i == n) return false;
  if(sum1>target) return false;
   if(dp[i][sum1]!=-1) return dp[i][sum1];
  if(sum1<target)
  {
    int c1 = fun(nums,i+1,sum1+nums[i],n,target,dp);
    int c2 = fun(nums,i+1,sum1,n,target,dp);
    return dp[i][sum1] = c1 || c2;
  }
  return dp[i][sum1] = fun(nums,i+1,sum1,n,target,dp);

}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
        }
          if(sum%2!=0) return false;
            int target = sum/2;
              vector<vector<int>>dp(n,vector<int>(target+1,-1));
      return fun(nums,0,0,n,target,dp); return true;
        return false;
    }
};