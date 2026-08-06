class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         vector<int>f;
        if(n == 1)
        {
            f.push_back(0);
            return f;
        }
        vector<vector<int>>adj(n);
        vector<int> indegree(n, 0);
        for(int i=0;i<edges.size();i++)
        {
            int s = edges[i][0];
            int d = edges[i][1];
            adj[s].push_back(d);
            adj[d].push_back(s);
            indegree[s]++;
            indegree[d]++;
        }
       queue<int>q;
       for(int i=0;i<n;i++)
       {
        if(indegree[i] == 1)
        {
            q.push(i);
        }
       }
       while(!q.empty())
       {
        int n1 = q.size();
        f.clear();
        while(n1--)
        {
           int node = q.front();
            q.pop();
            f.push_back(node);
            for(auto neigh : adj[node])
            {
                indegree[neigh]--;
                if(indegree[neigh] == 1)
                {
                    q.push(neigh);
                }
            }
        }

       
       
       }
return f;


    }
};