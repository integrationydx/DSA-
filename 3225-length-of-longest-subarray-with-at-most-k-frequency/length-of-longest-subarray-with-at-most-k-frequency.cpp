class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int low = 0;
        int high = 0;
        int maxi = INT_MIN;
        while(high<nums.size())
        {
            f[nums[high]]++;
            while(f[nums[high]] > k)
                {
                    f[nums[low]]--;
                    low++;
                    
                }
                maxi = max(maxi,high-low+1);
                high++;
            
        }
        return maxi;
    }
};