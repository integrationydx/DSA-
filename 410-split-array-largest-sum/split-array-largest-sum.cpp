class Solution {
public:
bool allocation(int mid,int k,vector<int>& nums)
{
    int allocated = 1; 
    int ele = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>mid) return false;
        if(ele + nums[i] > mid)
        {
            allocated+= 1;
            ele= nums[i];
        }
        else{
            ele+= nums[i];
        }
    }
    if(allocated > k) return false;
    return true;
}
    int splitArray(vector<int>& nums, int k) {
      int low = *max_element(nums.begin(),nums.end());
      int high = accumulate(nums.begin(), nums.end(), 0);
      while(low<=high)
      {
        int mid = low + (high-low)/2;
        if(allocation(mid,k,nums))
        {
            
            high = mid -1;
        }
        else{
            low = mid+1;
        }

      }
       return low;

    }
};