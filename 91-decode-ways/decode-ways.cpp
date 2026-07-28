class Solution {
public:
    int fun(string &s, vector<int> &dp, int i, int n)
    {
        if(i == n) return 1;
        if(i > n) return 0;

        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int c1 = fun(s, dp, i + 1, n);

        int c2 = 0;
        if(i + 1 < n)
        {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if(num >= 10 && num <= 26)
            {
                c2 = fun(s, dp, i + 2, n);
            }
        }

        return dp[i] = c1 + c2;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return fun(s, dp, 0, n);
    }
};