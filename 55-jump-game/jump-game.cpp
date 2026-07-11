class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mini = 0;
        for(int i=0;i<n;i++)
        {
            if(i>mini) return false;
            mini = max(mini,i+nums[i]);
        }
        return true;
    }
};