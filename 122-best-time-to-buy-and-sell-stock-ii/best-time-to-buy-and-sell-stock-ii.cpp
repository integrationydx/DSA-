class Solution {
public:
int fun(vector<int>& prices, int i, int n, int k,vector<vector<int>> &dp)
{
    if(i == n) return 0;
     if(dp[i][k]!=-1) return dp[i][k];
    if(k == 1)
    {
        int buy = -prices[i] + fun(prices, i+1, n, 0,dp);
        int skip = fun(prices, i+1, n, 1,dp);

        return dp[i][k] = max(buy, skip);
    }

    if(k == 0)
    {
        int sell = prices[i] + fun(prices, i+1, n, 1,dp);
        int skip = fun(prices, i+1, n, 0,dp);

        return dp[i][k] = max(sell, skip);
    }

    return 0;
}

    int maxProfit(vector<int>& prices) {
      int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));
      int k = 1;
      int x = fun(prices,0,n,1,dp);
      return max(0,x);
    }
};