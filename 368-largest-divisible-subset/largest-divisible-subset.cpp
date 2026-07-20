class Solution {
public:
int fun(int i,vector<int> &nums,int n,int prev,vector<vector<int>> &dp)
{
    if(i == n) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    if(prev == -1 || nums[i]%nums[prev]== 0)
    {
        int c1 = 1 + fun(i+1,nums,n,i,dp);
        int c2 = fun(i+1,nums,n,prev,dp);
        return dp[i][prev+1] = max(c1,c2);
    }
    return dp[i][prev+1] = fun(i+1,nums,n,prev,dp);

}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        fun(0,nums,n,-1,dp);
        vector<int> ans;

int i = 0;
int prev = -1;

while(i < n)
{
    int c1 = fun(i+1, nums, n, prev, dp);

    int c2 = -1;

    if(prev == -1 || nums[i] % nums[prev] == 0)
        c2 = 1 + fun(i+1, nums, n, i, dp);

    if(c2 >= c1)
    {
        ans.push_back(nums[i]);
        prev = i;
    }

    i++;
}

return ans;
    }
};