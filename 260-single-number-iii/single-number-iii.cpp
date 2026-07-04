class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>f;
        vector<int>g;
        for(int i=0;i<nums.size();i++)
        {
            f[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(f[nums[i]] == 1) g.push_back(nums[i]);
        }
        return g;
    }
};