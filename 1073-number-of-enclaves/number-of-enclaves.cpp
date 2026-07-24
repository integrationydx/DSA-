class Solution {
public:
bool valid(int i, int j, int n, int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        return true;
    }

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, 1, -1};

void dfs(vector<vector<int>>& grid, int n,int m,vector<vector<int>> &vis,int i,int j)
{
    vis[i][j] = 1;
    for(int k=0;k<4;k++)
    {
        int row = i + x[k];
        int col = j + y[k];
        if(valid(row,col,n,m) && grid[row][col] == 1 && vis[row][col] == false)
        {
           dfs(grid,n,m,vis,row,col);
        }

    }
}


    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                {
                  
                   if(vis[i][j] == 0 && grid[i][j] == 1 )
            {
                dfs(grid,n,m,vis,i,j);
            }
                }
              
            }
            
        }
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 1 && vis[i][j] == false)
        {
            count++;
        }
        }
       
     }
     return count;




    }
};