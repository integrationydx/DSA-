class Solution {
public:
    long long wonderfulSubstrings(string word) {

        unordered_map<int, long long> mp;

        mp[0] = 1;

        int mask = 0;
        long long ans = 0;

        for(char ch : word)
        {
            // Flip the bit corresponding to the current character
            mask ^= (1 << (ch - 'a'));

            // Case 1: All characters have even frequency
            ans += mp[mask];

            // Case 2: Exactly one character has odd frequency
            for(int i = 0; i < 10; i++)
            {
                ans += mp[mask ^ (1 << i)];
            }

            // Store current mask
            mp[mask]++;
        }

        return ans;
    }
};