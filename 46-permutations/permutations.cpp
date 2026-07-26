class Solution {
public:
void fun(vector<int> &ans,vector<vector<int>> &ds,vector<int> &nums,int n,vector<int>&vis)
{
    if(ans.size() == n)
    {
        ds.push_back(ans);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(vis[i] == false)
        {
            ans.push_back(nums[i]);
            vis[i] = true;
            fun(ans,ds,nums,n,vis);
            ans.pop_back();
            vis[i] = false;
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        vector<vector<int>>ds;
        vector<int>vis(n,0);
         fun(ans,ds,nums,n,vis);
         return ds;
    }
};