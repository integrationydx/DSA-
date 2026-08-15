class Solution {
public:

void fun(vector<int> &nums,vector<vector<int>> &ds,vector<int>&ans,int i,int n)
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

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<vector<int>>ds;
        vector<int>ans;
        fun(nums,ds,ans,0,n);
        int sum = 0;
        for(int i=0;i<ds.size();i++)
        {
            int x = 0;
            for(int j=0;j<ds[i].size();j++)
            {
                x^= ds[i][j];
            }
            sum+=x;
        }
        return sum;
    }
};