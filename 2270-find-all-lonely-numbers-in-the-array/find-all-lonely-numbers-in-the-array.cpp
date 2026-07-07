class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>f;
        vector<int>g;
        for(int i=0;i<nums.size();i++)
        {
            f[nums[i]]++;
        }
        for(auto it:f)
        {
            if(it.second == 1)
            {
               if(f.find(it.first+1)!=f.end()) continue;
               if(f.find(it.first-1)!=f.end()) continue;

               g.push_back(it.first);


               
            }
        }
        return g;
    }
};