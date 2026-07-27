class Solution {
public:
bool fun(string &s,vector<string>& wordDict, int i,vector<int> &dp)
{
  if(i == s.size()) return true;
   if(dp[i]!=-1) return dp[i];
  bool found = false;
  for(int k=0;k<wordDict.size();k++)
  {
   if(s.compare(i, wordDict[k].size(), wordDict[k])== 0)
   {
    if(fun(s,wordDict,i+wordDict[k].size(),dp)) return dp[i] = true;
   
   }
  }
  return dp[i] = found;

}

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n,-1);
         return fun(s,wordDict,0,dp);
    }
};