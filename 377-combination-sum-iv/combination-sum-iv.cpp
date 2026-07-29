class Solution {
public:
    int fun(vector<int>& nums, int target, int i,vector<vector<int>> &dp)
    {
        if(target == 0) return 1;
          if(target < 0) return 0;
          if(i == nums.size()) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        

        int pick = fun(nums, target - nums[i], 0,dp);

        int notPick = fun(nums, target, i + 1,dp);

        return dp[i][target] = pick + notPick;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
       vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return fun(nums, target, 0,dp);
    }
};