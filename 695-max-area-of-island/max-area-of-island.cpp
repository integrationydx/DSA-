class Solution {
public:
 int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

bool isValid(int row, int col, int n, int m)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

int dfs(vector<vector<int>>& grid,int n,int m,vector<vector<int>>& vis,int i,int j)
{
   int count = 1;
            vis[i][j] = 1;
            for(int k=0;k<4;k++)
            {
                int row = i + x[k];
                int col = j + y[k];
                if(isValid(row,col,n,m) == true && grid[row][col] == 1 && vis[row][col] == false)
                {
                   
                  count+=dfs(grid,n,m,vis,row,col);
                }
            }
            return count;

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == false)
                {
                  maxi = max(maxi,dfs(grid,n,m,vis,i,j));
                }
            }
        }
        if(maxi == INT_MIN) return 0;
        return maxi;
    }
};