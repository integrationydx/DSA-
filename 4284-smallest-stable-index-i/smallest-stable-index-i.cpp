class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int>f(n);
        vector<int>temp(n);
        f[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            f[i] = max(f[i-1],nums[i]);
        }
        temp[n-1] = nums[n-1];
        for(int i =n-2;i>=0;i--)
        {
            temp[i] = min(temp[i+1],nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            int stability = f[i] - temp[i];
            if(stability<=k) return i;
        }
        return -1;

    }
};