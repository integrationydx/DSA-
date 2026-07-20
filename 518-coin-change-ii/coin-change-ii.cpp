class Solution {
public:
int fun( vector<int>& coins, int i,int sum,int n,int amount,vector<vector<int>> &dp)
{
    if(i == n) 
    {
        if(sum == amount) return 1;
        return 0;
    }
    if(sum>amount) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int c1 = fun(coins,i,sum+coins[i],n,amount,dp);
    int c2 = fun(coins,i+1,sum,n,amount,dp);

    return dp[i][sum] = c1+c2;

}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int sum = 0;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fun(coins,0,0,n,amount,dp);
    }
};