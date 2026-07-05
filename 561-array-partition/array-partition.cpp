class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>f;
        for(int i=0;i<nums.size()-1;i+=2)
        {
            f.push_back({nums[i],nums[i+1]});
        }
        int sum = 0;
        for(int i=0;i<f.size();i++)
        {
            sum+= f[i].first;
        }
        return sum;
    }
};