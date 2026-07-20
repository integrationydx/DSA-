class Solution {
public:
int fun(vector<int>&prices,int i,int fee,int k,int n,vector<vector<int>> &dp)
{
    if(i == n) return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    if(k == 1) // this for buying shit // 
    {
       int buy = fun(prices,i+1,fee,0,n,dp) - prices[i];
       int skip = fun(prices,i+1,fee,1,n,dp);

       return dp[i][k] = max(buy,skip);
    }
    if(k == 0) // this for selling shit // 
    {
       int sell = fun(prices,i+1,fee,1,n,dp) + prices[i] - fee;
       int skip = fun(prices,i+1,fee,0,n,dp); 
       return dp[i][k] = max(sell,skip);
    }
    return 0;
}
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int k = 1;
        vector<vector<int>> dp(n,vector<int>(3,-1));
        int x = fun(prices,0,fee,k,n,dp);
        return max(0,x);
    }
};