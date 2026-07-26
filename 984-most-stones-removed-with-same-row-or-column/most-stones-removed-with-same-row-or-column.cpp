class Solution {
public:
void dfs(int node,vector<int> &vis,vector<vector<int>> &stones)
{
    vis[node] = 1;
    int n = stones.size();
    for(int i=0;i<n;i++)
    {
       if((vis[i] == false) && (stones[node][0] == stones[i][0] || stones[node][1] == stones[i][1]))
       {
        dfs(i,vis,stones);
       }
    }
}
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int m = stones[0].size();
        int count = 0;
        vector<int>vis(n,0);
       for(int i=0;i<n;i++)
       {
        if(vis[i] == false)
        {
            dfs(i,vis,stones);
            count++;
        }
       }
        return n - count;
    }
};