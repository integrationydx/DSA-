class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        unordered_map<string,int>f;
        for(int i=0;i<n;i++)
        {
            f[patterns[i]]++;
        }
        unordered_map<string,int>g;
        int n2 = word.size();
        for(int i=0;i<n2;i++)
        {
            for(int j=i;j<n2;j++)
            {
                string s = word.substr(i,j-i+1);
                g[s]++;
            }
        }
        int count = 0;
       for(auto it1: f)
       {
        if(g.find(it1.first)!= g.end())
        {
            count+= it1.second;
        }
        
       }
       return count;

    }
};