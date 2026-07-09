class Solution {
public:

void fun(int idx,int k,int n,vector<vector<int>>&ds,vector<int>&ans,int sum)
{
    if( ans.size() == k)
    {
        if(sum == n)
        {
           ds.push_back(ans);
        }
       
        return;
    }
      for(int i=idx;i<=9;i++)
      {
        if(sum>n) return;
        if(ans.size()>k) return;
        ans.push_back(i);
        fun(i+1,k,n,ds,ans,sum+i);
        ans.pop_back();
      }

}



    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ds;
        vector<int>ans;
        int sum = 0;
        fun(1,k,n,ds,ans,sum);
        return ds;
    }
};