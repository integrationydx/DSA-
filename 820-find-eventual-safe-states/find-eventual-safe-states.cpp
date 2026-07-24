class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>indeg(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
           indeg[i] = graph[i].size();
           for(auto neigh : graph[i])
    {
        adj[neigh].push_back(i);  
    }
        }

        queue<int>q;
        vector<int>res;
        for(int i=0;i<n;i++)
         {
            if(indeg[i] == 0) q.push(i);
         }
         while(!q.empty())
         {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j];
                indeg[neigh]--;
                if(indeg[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
         }
         sort(res.begin(),res.end());

return res;











    }
};