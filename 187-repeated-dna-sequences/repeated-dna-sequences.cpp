class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;

        for(int i = 0; i + 9 < s.size(); i++)
        {
            string temp = s.substr(i, 10);

            if(seen.find(temp) != seen.end())
            {
                repeated.insert(temp);
            }
            else
            {
                seen.insert(temp);
            }
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};