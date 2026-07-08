class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        vector<int>suffix(n);
        suffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1] + nums[i];
        }
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            res.push_back(abs(prefix[i]-suffix[i]));
        }
        return res;

    }
};