class Solution {
public:
    void create(vector<vector<int>>& prerequisites, int numCourses, vector<vector<int>> &adj)
    {
        for(int i = 0; i < prerequisites.size(); i++)
        {
            vector<int> edge = prerequisites[i];
            int src = edge[0];
            int dst = edge[1];

            adj[dst].push_back(src);
        }
    }

    bool dfs(vector<vector<int>>& adj, int numCourses, vector<bool> &vis,
             vector<bool> &path, int node)
    {
        vis[node] = true;
        path[node] = true;

        for(int i = 0; i < adj[node].size(); i++)
        {
            int neigh = adj[node][i];

            if(vis[neigh] == false)
            {
                if(dfs(adj, numCourses, vis, path, neigh))
                    return true;
            }
            else if(path[neigh] == true)
            {
                return true;
            }
        }

        path[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        create(prerequisites, numCourses, adj);

        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);

        for(int i = 0; i < numCourses; i++)
        {
            if(vis[i] == false)
            {
                if(dfs(adj, numCourses, vis, path, i))
                    return false;
            }
        }

        return true;
    }
};