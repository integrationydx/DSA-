class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;
        int prefixSum = 0;
        int ans = 0;

        
        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                prefixSum += -1;
            else
                prefixSum += 1;

            if (mp.find(prefixSum) != mp.end()) {
                ans = max(ans, i - mp[prefixSum]);
            }
            else {
                mp[prefixSum] = i;
            }
        }

        return ans;
    }
};