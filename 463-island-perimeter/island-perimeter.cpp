class Solution {
public:
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

bool isValid(int row, int col, int n, int m)
{
    return row >= 0 && row < n && col >= 0 && col < m;
}

int dfs(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &vis)
{
    if(!isValid(i, j, n, m))
        return 1;

  
    if(grid[i][j] == 0)
        return 1;

  
    if(vis[i][j])
        return 0;

    vis[i][j] = 1;
    int ans = 0;
    for(int k=0;k<4;k++)
    {
        int row = i + x[k];
        int col = j + y[k];
       
       ans+= dfs(row,col,m,n,grid,vis);
    }
    return ans;
}

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == false)
                {
                 return  dfs(i,j,m,n,grid,vis);
                }
            }
        }
   return 0;
    }
};