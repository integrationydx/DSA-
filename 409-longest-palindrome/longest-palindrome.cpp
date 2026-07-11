class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            f[s[i]]++;
        }
        bool odd = false;
       int ans = 0;
       for(auto it:f)
       {
        if(it.second%2 == 0)
        {
            ans+= it.second;
        }
        else{
              ans+= it.second-1;
              odd = true;
        }
       }
        if(odd) ans++;
               return ans;
    }
};