class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int x = *max_element(nums.begin(),nums.end());
        vector<int> temp = nums;
        sort(nums.begin(),nums.end());
        int n = nums.size() -1;
        for(int i=0;i<n;i++)
        {
            if(x>=2*nums[i]) continue;
            else{
                return -1;
            }
        }
        int maxi = temp[0];
        int idx = 0;
       for(int i=0;i<temp.size();i++)
       {
           if(temp[i]>maxi) 
           {
            maxi = temp[i];
            idx = i;
           }

       }
       return idx;
    }
};