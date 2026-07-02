class Solution {
public:
    int beautySum(string s) {
       vector<int>g;
       int n = s.size();
                      int sumi =0;

       for(int i=0;i<n;i++)
       {
               unordered_map<char,int>f;
         for(int j=i;j<n;j++)
         {
           f[s[j]]++;
           int maxi = INT_MIN;
           int mini = INT_MAX;
           for(auto it:f)
           {
            mini = min(mini,it.second);
            maxi = max(maxi,it.second);
           }
           sumi+= maxi-mini;
       
       }
       }
              return sumi;

    }
};