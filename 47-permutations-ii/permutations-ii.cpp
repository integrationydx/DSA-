class Solution {
public:
void fun(vector<int>& nums,vector<vector<int>>& ds,vector<int> &ans,int n,vector<int> &vis)
{
    if(ans.size() == n)
    {
        for(int i=0;i<ds.size();i++)
        {
           if(ds[i] == ans) return;
        }
         ds.push_back(ans);
    return;
    }
   


         for(int i=0;i<nums.size();i++)
    {
        if(vis[i] == false)
        {
            ans.push_back(nums[i]);
            vis[i] = true;
            fun(nums,ds,ans,n,vis);
            ans.pop_back();
            vis[i] = false;
        }
    }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<vector<int>>ds;
        vector<int>vis(n,0);
        fun(nums,ds,ans,n,vis);
        return ds;

    }
};