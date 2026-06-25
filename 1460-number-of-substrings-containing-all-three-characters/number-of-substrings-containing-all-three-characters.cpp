class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> freq(3, 0);

        int low = 0;
        int count = 0;
        int n = s.size();

        for(int high = 0; high < n; high++)
        {
            freq[s[high] - 'a']++;

            while(freq[0] > 0 &&
                  freq[1] > 0 &&
                  freq[2] > 0)
            {
                count += n - high;

                freq[s[low] - 'a']--;
                low++;
            }
        }

        return count;
    }
};