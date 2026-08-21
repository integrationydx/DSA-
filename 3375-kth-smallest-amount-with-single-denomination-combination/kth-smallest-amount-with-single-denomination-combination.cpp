class Solution {
public:

    long long lcmLimit(long long a, long long b, long long limit)
    {
        long long g = gcd(a, b);

        if (a / g > limit / b)
            return limit + 1;

        long long l = (a / g) * b;

        if (l > limit)
            return limit + 1;

        return l;
    }

    long long countNumbers(vector<int>& nums, long long x)
    {
        int n = nums.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); mask++)
        {
            long long l = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    bits++;

                    l = lcmLimit(l, nums[i], x);

                    if (l > x)
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long cur = x / l;

            if (bits % 2 == 1)
                count += cur;
            else
                count -= cur;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& nums, int k)
    {
        long long low = *min_element(nums.begin(), nums.end());
        long long high = low * 1LL * k;

        long long ans = high;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            long long count = countNumbers(nums, mid);

            if (count >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};