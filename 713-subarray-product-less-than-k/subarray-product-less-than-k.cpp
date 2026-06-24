class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1)
        {
            return 0;
        }

        int low = 0;
        int high = 0;

        int product = 1;
        int ans = 0;

        while(high < nums.size())
        {
            product *= nums[high];

            while(product >= k)
            {
                product /= nums[low];
                low++;
            }

            ans += (high - low + 1);

            high++;
        }

        return ans;
    }
};