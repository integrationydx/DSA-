class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        vector<int>f;
        int n = nums.size();
       int best_ending = nums[0];
       int best_sum = nums[0];

       for(int i=1;i<n;i++)
       {
        int val = best_ending + nums[i];
        if(nums[i]>nums[i-1])
        {
           best_ending+= nums[i];
        }
        
        else{
           
            best_ending = nums[i];
        }
        best_sum = max(best_ending,best_sum);

       }
       
        return best_sum;










      
    }
};