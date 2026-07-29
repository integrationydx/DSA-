class Solution {
public:
    bool fun(vector<int>& stones, int i, int lastJump,
             vector<vector<int>>& dp,
             unordered_map<int,int>& mp)
    {
        int n = stones.size();

        if(i == n - 1)
            return true;

        if(dp[i][lastJump] != -1)
            return dp[i][lastJump];

        for(int jump = lastJump - 1; jump <= lastJump + 1; jump++)
        {
            if(jump <= 0)
                continue;

            int nextPos = stones[i] + jump;

            if(mp.find(nextPos) != mp.end())
            {
                int nextIndex = mp[nextPos];

                if(fun(stones, nextIndex, jump, dp, mp))
                    return dp[i][lastJump] = true;
            }
        }

        return dp[i][lastJump] = false;
    }

    bool canCross(vector<int>& stones) {

        int n = stones.size();

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++)
            mp[stones[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return fun(stones, 0, 0, dp, mp);
    }
};