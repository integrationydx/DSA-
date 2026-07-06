class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = -1;   // remainder 0 before the array starts

        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            int rem = prefixSum % k;

            // Handle negative remainders (good practice)
            if (rem < 0)
                rem += k;

            if (mp.find(rem) != mp.end()) {

                // Check if subarray length >= 2
                if (i - mp[rem] >= 2)
                    return true;

            } else {
                // Store only the first occurrence
                mp[rem] = i;
            }
        }

        return false;
    }
};