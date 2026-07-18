class Solution {
public:
    int fun(vector<int>& cost, int i, int n, vector<int>& dp)
    {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int c1 = fun(cost, i + 1, n, dp);
        int c2 = fun(cost, i + 2, n, dp);

        return dp[i] = cost[i] + min(c1, c2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        return min(fun(cost, 0, n, dp),
                   fun(cost, 1, n, dp));
    }
};