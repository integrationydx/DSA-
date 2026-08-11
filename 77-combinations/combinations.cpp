class Solution {
public:
void fun(int n,int k,vector<int> &ans,vector<vector<int>> &ds,int i,vector<int> &temp)
{
    if(k == 0)
    {
        ds.push_back(ans);
        return;
    }
    if(i == n) return;

    ans.push_back(temp[i]);
    fun(n,k-1,ans,ds,i+1,temp);
    ans.pop_back();

    fun(n,k,ans,ds,i+1,temp);
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        vector<vector<int>>ds;
        vector<int> temp;
        for(int i=1;i<=n;i++)
        {
              temp.push_back(i);
        }
         fun(n,k,ans,ds,0,temp);
        return ds;
    }
};