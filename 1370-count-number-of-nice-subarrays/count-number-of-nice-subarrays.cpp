class Solution {
public:
    int fun(vector<int>& f, int k)
    {
        if(k < 0)
        {
            return 0;
        }

        int low = 0;
        int sum = 0;
        int count = 0;

        for(int high = 0; high < f.size(); high++)
        {
            sum += f[high];

            while(sum > k)
            {
                sum -= f[low];
                low++;
            }

            count += (high - low + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k)
    {
        vector<int> f;

        for(int x : nums)
        {
            f.push_back(x % 2);
        }

        return fun(f, k) - fun(f, k - 1);
    }
};