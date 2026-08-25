class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=1;i<INT_MAX;i++)
        {
            int multiple = k*i;
            bool found = false;
            for(int j=0;j<n;j++)
        {
              if(nums[j] == multiple) found = true;
        }
        if(found != true)
        {
         return multiple;
        }
        }
        return -1;
        
    }
};