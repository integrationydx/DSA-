class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>even;
            unordered_map<int,int>odd;
            for(int j=i;j<n;j++)
            {
                 if(nums[j]%2 == 0) even[nums[j]]++;
                 else{
                    odd[nums[j]]++;
                 }
                 if(even.size() == odd.size())
                 {
                    maxi = max(maxi,j-i+1);
                 }
            }
        }
        if(maxi == INT_MIN) return 0;
        return maxi;
    }
};