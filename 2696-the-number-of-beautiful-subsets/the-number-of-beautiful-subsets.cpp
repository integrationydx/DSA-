class Solution {
public:
bool help(vector<int> &v,int k)
{
    int n1 = v.size();
    for(int i=0;i<n1;i++)
    {
        for(int j=i+1;j<n1;j++)
        {
          if(abs(v[i] - v[j]) == k)
                    return false;
        }
    }
    return true;
}

void fun(vector<int> &nums,vector<vector<int>> &ds,vector<int> &ans,int i,int n)
{
    if(i == n)
    {
        ds.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    fun(nums,ds,ans,i+1,n);
    ans.pop_back();

    fun(nums,ds,ans,i+1,n);
}


    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>ds;
        vector<int>ans;
        fun(nums,ds,ans,0,n);
        int count = 0;
        for(int i = 0; i < ds.size(); i++)
    {
        if(!ds[i].empty() && help(ds[i], k))
            count++;
    }
    return count;
    }
};