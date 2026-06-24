class Solution {
public:
    bool res = true;

    void dfs(vector<vector<int>>& adj, int node, int c, vector<int>& colors)
    {
        colors[node] = c;

        for(int j = 0; j < adj[node].size(); j++)
        {
            int neigh = adj[node][j];

            if(colors[neigh] != -1)
            {
                if(colors[neigh] == c)
                {
                    res = false;
                    return;
                }
            }
            else
            {
                dfs(adj, neigh, 1 - c, colors);
            }
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < dislikes.size(); i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n + 1, -1);

        for(int i = 1; i <= n; i++)
        {
            if(colors[i] == -1)
            {
                dfs(adj, i, 0, colors);
            }
        }

        return res;
    }
};