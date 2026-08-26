class Solution {
public:

    int k;

    bool fun(string res)
    {
        if(res.size() == 0 && k == 0) return true;
        if(res.size() == 0 && k != 0) return false;

        unordered_map<char,int> f;

        for(int i = 0; i < res.size(); i++)
        {
            f[res[i]]++;
        }

        if(f.find('1') != f.end())
        {
            if(f['1'] == k)
            {
                return true;
            }
        }

        return false;
    }

    string shortestBeautifulSubstring(string s, int x) {
        k = x;

        int n = s.size();
        int len = INT_MAX;
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                string temp = s.substr(i, j-i+1);

                if(fun(temp))
                {
                    if(j-i+1 < len || j-i+1 == len && temp<ans)
                    {
                        len = j-i+1;
                        ans = temp;
                    }
                }
            }
        }

        return ans;
    }
};