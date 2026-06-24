class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();

        if(n < 3)
        {
            return 0;
        }

        int ans = 0;

        int low = 0;
        int high = 1;

        while(high < n)
        {
            int diff = nums[high] - nums[high - 1];

            while(high < n && nums[high] - nums[high - 1] == diff)
            {
                high++;
            }

            int len = high - low;

            if(len >= 3)
            {
                ans += (len - 2) * (len - 1) / 2;
            }

            low = high - 1;
        }

        return ans;
    }
};