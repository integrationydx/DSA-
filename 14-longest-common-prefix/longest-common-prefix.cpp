class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";
        string first = strs[0];

        for(int len = 1; len <= first.size(); len++)
        {
            string candidate = first.substr(0, len);

            bool ok = true;

            
            for(int i = 1; i < strs.size(); i++)
            {
                
                if(strs[i].size() < len)
                {
                    ok = false;
                    break;
                }

                // Compare the prefix
                if(strs[i].substr(0, len) != candidate)
                {
                    ok = false;
                    break;
                }
            }

            if(ok)
            {
                ans = candidate;
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};