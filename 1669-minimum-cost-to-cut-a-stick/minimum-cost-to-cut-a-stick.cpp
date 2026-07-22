class Solution {
public:
int fun(vector<int> &nums,int i,int j,vector<vector<int>> &dp)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int res = INT_MAX;
    for(int k=i;k<=j;k++)
    {
        int cost = nums[j+1] - nums[i-1];
        int r = cost + fun(nums,i,k-1,dp) + fun(nums,k+1,j,dp);

        res = min(res,r);
    }
    return  dp[i][j] = res;
}
    int minCost(int n, vector<int>& cuts) {
        vector<int> nums;
        nums.push_back(0);
        for(int i=0;i<cuts.size();i++)
        {
            nums.push_back(cuts[i]);
        }
        nums.push_back(n);
        sort(nums.begin(),nums.end());
        int s = nums.size();
         vector<vector<int>>dp(s,vector<int>(s,-1));
        return fun(nums,1,s-2,dp);
    }
};