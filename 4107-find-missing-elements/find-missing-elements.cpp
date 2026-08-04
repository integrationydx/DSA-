class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>f;
        vector<int>g;
        for(int i=0;i<nums.size();i++)
        {
            f[nums[i]]++;
        }
        int i = *min_element(nums.begin(),nums.end());
        int a = *max_element(nums.begin(),nums.end());
        for(i;i<a;i++)
        {
            if(f.find(i)!=f.end()) continue;
            else{
                g.push_back(i);
            }
        }
        sort(g.begin(),g.end());
        return g;
    }
};