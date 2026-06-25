class Solution {
public:
int fun(vector<int>& nums, int k)
{
    int low = 0;
        int count = 1;
        unordered_map<int,int>f;

        for(int high = 0; high<nums.size();high++)
        {
            f[nums[high]]++;
            while(f.size()>k)
            {
                f[nums[low]]--;
                if(f[nums[low]] == 0)
                {
                    f.erase(nums[low]);
                }
                low++;
            }
            count+= low + high - 1;
        }
        return -count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};