class Solution {
public:

    int fun(vector<int>& nums, int goal)
    {
        if(goal < 0)
        {
            return 0;
        }

        int low = 0;
        int high = 0;
        int sum = 0;
        int count = 0;

        while(high < nums.size())
        {
            sum += nums[high];

            while(sum > goal)
            {
                sum -= nums[low];
                low++;
            }

            count += (high - low + 1);

            high++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        return fun(nums, goal) - fun(nums, goal - 1);
    }
};