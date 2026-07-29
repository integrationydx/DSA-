class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       unordered_map<int,int>f;
       for(int i=0;i<nums.size();i++)
       {
         f[nums[i]]++;
       }
       vector<int>g;
    int x = nums.size();
      for(int i=1;i<=x;i++)
      {
        if(f.find(i)!=f.end()) continue;
        else{
            g.push_back(i);
        }
      }
      return g;
    }
};