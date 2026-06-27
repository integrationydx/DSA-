class Solution {
public:
int sumD(vector<int>& nums, int div)
{
    int sum = 0;
    for(int num : nums)
    {
        sum+= ceil((double)num / div);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end()) ;
       int ans = -1;
       while(low<=high)
       {
        int mid = (low+high)/2;
        if(sumD(nums,mid) <= threshold)
        {
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid+1;
        }
       }
       return ans;

    }
};