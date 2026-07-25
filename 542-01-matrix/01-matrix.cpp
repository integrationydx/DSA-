class Solution {
public:
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};

bool valid(int i,int j,int n,int m)
{
    if(i<0 || i>= n || j<0 || j>=m)
    {
        return false;
    }
    return true;

}


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
int m = mat[0].size();

vector<vector<int>> vis(n, vector<int>(m, 0));
vector<vector<int>> dist(n, vector<int>(m, 0));
queue<pair<int,int>> q;

for(int i = 0; i < n; i++)
{
    for(int j = 0; j < m; j++)
    {
        if(mat[i][j] == 0)
        {
            q.push({i,j});
            vis[i][j] = 1;
            dist[i][j] = 0;
        }
    }
}

while(!q.empty())
{
    auto node = q.front();
    q.pop();

    int i = node.first;
    int j = node.second;

    for(int k = 0; k < 4; k++)
    {
        int row = i + x[k];
        int col = j + y[k];

        if(valid(row,col,n,m) && !vis[row][col])
        {
            vis[row][col] = 1;
            dist[row][col] = dist[i][j] + 1;
            q.push({row,col});
        }
    }
}
return dist;
    }
};