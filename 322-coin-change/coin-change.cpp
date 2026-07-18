class Solution {
public:
    int fun(vector<int> &coins, int curr_cost, int amount, int n, vector<int> &dp)
    {
        if(curr_cost == 0)
            return 0;

        if(curr_cost < 0)
            return INT_MAX;

        if(dp[curr_cost] != -2)
            return dp[curr_cost];

        int mini = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            int temp = fun(coins, curr_cost - coins[i], amount, n, dp);

            if(temp != INT_MAX)
            {
                mini = min(mini, 1 + temp);
            }
        }

        return dp[curr_cost] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

       
        vector<int> dp(amount + 1, -2);

        int ans = fun(coins, amount, amount, n, dp);

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};