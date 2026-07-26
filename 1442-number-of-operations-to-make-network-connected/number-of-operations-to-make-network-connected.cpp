class Solution {
public:

void dfs(vector<int> &vis,vector<vector<int>> &adj,int node)
{
    vis[node] = 1;
    for(int i=0;i<adj[node].size();i++)
    {
        int neigh = adj[node][i];
        if(vis[neigh] == false)
        {
            dfs(vis,adj,neigh);;
        }
    }
}

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        int count = 0;
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++)
        {
            int src = connections[i][0];
            int dst = connections[i][1];
            adj[src].push_back(dst);
            adj[dst].push_back(src);
        }
    
    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i] == false)
        {
            dfs(vis,adj,i);
            count++;
        }
    }
    return count-1;
    }
};