class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
            int maxi = INT_MIN;
        int maxIdx = 0;
       int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                maxIdx = i;
            }
        }

        int mini = INT_MAX;
        int minIdx = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] < mini)
            {
                mini = nums[i];
                minIdx = i;
            }
        }

        int a = min(maxIdx, minIdx);
        int b = max(maxIdx, minIdx);

        return min({
            b + 1,
            n - a,
            (a + 1) + (n - b)
        });




    }
};