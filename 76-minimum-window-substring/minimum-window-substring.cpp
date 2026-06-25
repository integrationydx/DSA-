class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> need;
        unordered_map<char,int> window;

        for(char c : t)
        {
            need[c]++;
        }

        int required = need.size();
        int formed = 0;

        int low = 0;

        int minlen = INT_MAX;
        int start = 0;

        for(int high = 0; high < s.size(); high++)
        {
            char ch = s[high];

            window[ch]++;

            if(need.count(ch) &&
               window[ch] == need[ch])
            {
                formed++;
            }

            while(formed == required)
            {
                if(high - low + 1 < minlen)
                {
                    minlen = high - low + 1;
                    start = low;
                }

                char left = s[low];

                window[left]--;

                if(need.count(left) &&
                   window[left] < need[left])
                {
                    formed--;
                }

                low++;
            }
        }

        if(minlen == INT_MAX)
        {
            return "";
        }

        return s.substr(start, minlen);
    }
};