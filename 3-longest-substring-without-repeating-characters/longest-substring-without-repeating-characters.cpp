class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            vector<int> freq(256, 0);

            for(int j = i; j < n; j++)
            {
                freq[s[j]]++;

                if(freq[s[j]] > 1)
                {
                    break;
                }

                maxlen = max(maxlen, j - i + 1);
            }
        }

        return maxlen;
    }
};