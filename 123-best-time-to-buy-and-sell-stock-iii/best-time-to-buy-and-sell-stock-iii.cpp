class Solution {
public:
int fun(vector<int>& prices, int i,int n,int k,vector<vector<int>> &dp)
{
    if(i == n) return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    if(k == 0) return 0;
    if(k == 4) // this is for when we buy
    {
      int buy = fun(prices,i+1,n,3,dp) - prices[i];
      int skip = fun(prices,i+1,n,4,dp);
      return dp[i][k] = max(buy,skip);
    }
    if(k == 3) // selling for the first time
    {
        int sell = fun(prices,i+1,n,2,dp) + prices[i];
        int skip = fun(prices,i+1,n,3,dp);

        return dp[i][k] = max(sell,skip);
    }
    if(k == 2) // buying for the 2nd time 
    {
      int buy = fun(prices,i+1,n,1,dp) - prices[i];
      int skip = fun(prices,i+1,n,2,dp);
      return dp[i][k] = max(buy,skip);
    }
    if(k == 1) // selling for the 2nd time 
    {
        int sell = fun(prices,i+1,n,0,dp) + prices[i];
        int skip = fun(prices,i+1,n,1,dp);
        return dp[i][k] = max(sell,skip);
    }
    return 0;
}
    int maxProfit(vector<int>& prices) {
        int k = 4;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -1));
        int gain = fun(prices,0,n,k,dp);
        return max(0,gain);
    }
};