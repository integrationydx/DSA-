class Solution {
public:
int fun(string &word1,string &word2, int i, int j, int n,int m, vector<vector<int>> &dp)
    {
        if(i == n || j == m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j])
        {
            return dp[i][j] = 1 + fun(word1,word2, i+1, j+1, n,m, dp);
        }

        int c1 = fun(word1,word2, i+1, j, n,m ,dp);
        int c2 = fun(word1,word2, i, j+1, n,m, dp);

        return dp[i][j] = max(c1, c2);
    }

    int minDistance(string word1, string word2) {
          int n = word1.size();
          int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int x = fun(word1,word2, 0, 0, n,m, dp);
        int y = (n-x) + (m-x);
        return y;
    }
};