class Solution {
public:
int fun(vector<int>& nums, int i,int n,vector<int> &dp)
{
    if(i >= n) return 0;
    if(dp[i]!=-1) return dp[i];
    int c1 = nums[i] + fun(nums,i+2,n,dp);
    int c2 = fun(nums,i+1,n,dp);
    return dp[i] = max(c1,c2);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        if(n == 1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
       
        int ans1 = fun(nums, 0, n-1, dp1);
        int ans2 = fun(nums, 1, n, dp2);

        return max(ans1, ans2);
    }
};