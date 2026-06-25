class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count = 0;
        for(int i =0;i<nums.size();i++)
        {
            unordered_map<int,int>f;
            
            for(int j=i;j<nums.size();j++)
            {
                 f[nums[j]]++;
                 int len = j - i + 1;
                 
                   if(f[target] > len/2)
                   {
                    count++;
                   }
                    }
                 }

            
            
        
        return count;
    }
};