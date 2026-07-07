class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>f;
        for(int i=0;i<nums.size();i++)
        {
            f[nums[i]]++;
        }
        int sumi = 0;
        for(auto it:f)
        {
            if(it.second == 1)
            {
                sumi+= it.first;
            }
        }
        return sumi;
    }
};