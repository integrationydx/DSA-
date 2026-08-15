class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
            int x = 0;
        bool nonzero = false;

        for(int num : nums)
        {
            x ^= num;

            if(num != 0)
                nonzero = true;
        }

        if(x != 0)
            return nums.size();

        if(nonzero)
            return nums.size() - 1;

        return 0;
            }
};