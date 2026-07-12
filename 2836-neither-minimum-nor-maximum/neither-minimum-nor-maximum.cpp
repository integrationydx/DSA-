class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() == 2) return -1;
        if(nums.size() == 1) return -1;
        if(nums.size() == 0) return -1;
        sort(nums.begin(),nums.end());
        return nums[1];
    }
};