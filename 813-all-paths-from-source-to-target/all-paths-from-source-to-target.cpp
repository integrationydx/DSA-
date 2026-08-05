class Solution {
public:
void fun(vector<vector<int>>&adj,int node,vector<int>&ans,vector<vector<int>> &ds)
{
    ans.push_back(node);
    if(node == adj.size()-1) 
    {
        ds.push_back(ans);
        return;
    }
    for(int i=0;i<adj[node].size();i++)
    {
        int neigh = adj[node][i];
        fun(adj,neigh,ans,ds);
        ans.pop_back();
    }
}
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<int>ans;
        vector<vector<int>>ds;
        int n = adj.size();
       fun(adj,0,ans,ds);
       return ds;

    }
};