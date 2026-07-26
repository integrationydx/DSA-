class Solution {
public:
    const int MOD = 1e9 + 7;

    int dfs(int node, int dest, vector<vector<int>> &adj, vector<int> &dp)
    {
        if(node == dest) return 1;

        if(dp[node] != -1) return dp[node];

        long long ways = 0;

        for(int neigh : adj[node])
        {
            ways = (ways + dfs(neigh, dest, adj, dp)) % MOD;
        }

        return dp[node] = ways;
    }

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

       
        for(int i = 0; i < n - 1; i++)
        {
            bool changed = false;

            for(auto &e : roads)
            {
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                if(dist[u] != LLONG_MAX && dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                    changed = true;
                }

                if(dist[v] != LLONG_MAX && dist[u] > dist[v] + wt)
                {
                    dist[u] = dist[v] + wt;
                    changed = true;
                }
            }

            if(!changed) break;
        }

      
        vector<vector<int>> adj(n);

        for(auto &e : roads)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(dist[u] + wt == dist[v])
                adj[u].push_back(v);

            if(dist[v] + wt == dist[u])
                adj[v].push_back(u);
        }

        vector<int> dp(n, -1);

        return dfs(0, n - 1, adj, dp);
    }
};