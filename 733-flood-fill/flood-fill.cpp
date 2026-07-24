class Solution {
public:

int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool valid(int i,int j,int n,int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        return true;
    }

void dfs(vector<vector<int>>& image, int sr, int sc,vector<vector<bool>> &vis,int og,int color,int n,int m)
{
    vis[sr][sc] = true;
                image[sr][sc] = color;

    for(int k=0;k<4;k++)
    {
        int row = sr + x[k];
        int col = sc + y[k];
        if(valid(row,col,n,m) && vis[row][col] == false && image[row][col] == og)
        {
                       dfs(image,row,col,vis,og,color,n,m);
        }
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int og = image[sr][sc];

                vector<vector<bool>> vis(n, vector<bool>(m, false));
             dfs(image,sr,sc,vis,og,color,n,m);
           return image;
          
    }
};