class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        vector<int> f;

        for (int i = 0; i < nums.size(); i++) {
            f.push_back(abs(nums[i]));
        }

        int mini = INT_MAX;
        for (int i = 0; i < f.size(); i++) {
            mini = min(mini, f[i]);
        }

        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) == mini) {
                ans = max(ans, nums[i]);   
            }
        }

        return ans;
    }
};