class Solution {
public:
    int fun(vector<int>& nums, int i, int j,vector<vector<int>> &dp)
    {
        if(i == j)
        {
            return nums[i];
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int takeLeft = nums[i] - fun(nums, i + 1, j,dp);
        int takeRight = nums[j] - fun(nums, i, j - 1,dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(nums, 0, nums.size() - 1,dp) >= 0;
    }
};