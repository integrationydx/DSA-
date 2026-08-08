class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 1;
        while(j < nums.size())
        {
            if(i == j)
            {
                j++;
            }
            else if(nums[j] - nums[i] == k)
            {
                count++;
                i++;
                j++;
                while(j < nums.size() && nums[j] == nums[j-1])
                {
                    j++;
                }
            }
            else if(nums[j] - nums[i] < k)
            {
                j++;
            }
            else
            {
                i++;
            }
        }

        return count;
    }
};