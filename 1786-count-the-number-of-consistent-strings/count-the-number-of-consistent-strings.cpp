class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        unordered_map<char, int> f;

        
        for(char c : allowed)
        {
            f[c]++;
        }

        int count = 0;

      
        for(string word : words)
        {
            bool ok = true;

           
            for(char c : word)
            {
                if(f.find(c) == f.end())
                {
                    ok = false;
                    break;
                }
            }

            if(ok)
                count++;
        }

        return count;
    }
};