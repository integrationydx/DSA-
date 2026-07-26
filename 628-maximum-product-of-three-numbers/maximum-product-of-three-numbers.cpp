class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x = 0;
        int n = nums.size();
        int count = 0;
        int y = nums[n-1]*nums[n-2]*nums[n-3];
        int z = nums[0]*nums[1]*nums[n-1];
       x = max(y,z);
        return x;
    }
};