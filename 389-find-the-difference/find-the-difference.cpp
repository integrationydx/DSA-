class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>f;
                unordered_map<char,int>g;
        char res;
        for(int i=0;i<s.size();i++)
        {
            f[s[i]]++;
        }
        for(int j=0;j<t.size();j++)
        {
            g[t[j]]++;
        }

        for(auto it:g)
        {
           if(f[it.first] == g[it.first])
            {
                continue;
            }
            else{
                  return it.first;
            }
        }
       return -1;






    }
};