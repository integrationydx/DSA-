class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> ans;
        vector<unordered_map<char,int>> maps;

        for(int i = 0; i < n; i++)
        {
            unordered_map<char,int> f;

            
            for(int j = 0; j < strs[i].size(); j++)
            {
                f[strs[i][j]]++;
            }

            bool found = false;

          
            for(int j = 0; j < maps.size(); j++)
            {
                if(f == maps[j])
                {
                    ans[j].push_back(strs[i]);
                    found = true;
                    break;
                }
            }

          
            if(!found)
            {
                maps.push_back(f);

                vector<string> temp;
                temp.push_back(strs[i]);

                ans.push_back(temp);
            }
        }

        return ans;
    }
};