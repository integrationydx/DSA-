class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        vector<int>f;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int sum = nums[i];
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[j-1]) 
                {
                    sum+= nums[j];
                }
                else{
                    break;
                }
            }
                                f.push_back(sum);


        }
        return *max_element(f.begin(),f.end());
    }
};