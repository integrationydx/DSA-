class Solution {
public:
bool compare(string &a,string &b)
{
    if(b.size() != a.size() + 1)  return false;
    int i = 0;
    int j = 0;
    int count = 0;
    while(i<a.size() && j<b.size())
    {
        if(a[i] == b[j]) 
        {
            i++;
            j++;
        }
        else{
            count++;
            j++;
            if(count>1) return false;
        }
    }
    return true;
}

int fun(int i,vector<string>& words, int n,int prev, vector<vector<int>> &dp)
{
    if(i == n) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    if(prev == -1 || compare(words[prev],words[i]))
    {
        int c1 = 1+ fun(i+1,words,n,i,dp);
        int c2 = fun(i+1,words,n,prev,dp);

        return dp[i][prev+1] = max(c1,c2);
    }
    return dp[i][prev+1] = fun(i+1,words,n,prev,dp);
    
}

    int longestStrChain(vector<string>& words) {
        int n = words.size();
       sort(words.begin(), words.end(),
     [](string &a, string &b){
         return a.size() < b.size();
     });
     vector<vector<int>>dp(n,vector<int>(n+1,-1));
     return fun(0,words,n,-1,dp);
    }
};