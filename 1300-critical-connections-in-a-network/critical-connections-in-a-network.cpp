class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent,
             vector<int> &vis,
             vector<vector<int>> &adj,
             vector<int> &tin,
             vector<int> &low,
             vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neigh = adj[node][j];

            if (neigh == parent)
                continue;

            if (!vis[neigh])
            {
                dfs(neigh, node, vis, adj, tin, low, bridges);

                low[node] = min(low[node], low[neigh]);

                
                if (low[neigh] > tin[node])
                {
                    bridges.push_back({node, neigh});
                }
            }
            else
            {
               
                low[node] = min(low[node], tin[neigh]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for (int i = 0; i < connections.size(); i++)
        {
            int s = connections[i][0];
            int d = connections[i][1];

            adj[s].push_back(d);
            adj[d].push_back(s);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);

        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};