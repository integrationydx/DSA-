class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<int,int>f;
        int low = 0;
        int high = 0;
        int count = 0;
        while(high<n)
        {
            f[s[high]]++;
            while(f[s[high]]>2)
            {
                f[s[low]]--;
                low++;
            }
            high++;
            count = max(count,high-low);
        }
        return count;
        
    }
};