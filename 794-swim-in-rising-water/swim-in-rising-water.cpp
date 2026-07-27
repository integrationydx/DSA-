class Solution {
public:
bool isValid(int i, int j, int n)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int curr = INT_MIN;
        priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
> pq;
vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

dist[0][0] = grid[0][0];
pq.push({grid[0][0],{0,0}});
while(!pq.empty())
{
    auto p = pq.top();
    pq.pop();
    int val = p.first;
    int i = p.second.first;
    int j = p.second.second;
    if (i == n-1 && j == n-1)
    return val;

    if(val>dist[i][j]) continue;
    for(int k=0;k<4;k++)
    {
        int row = i + x[k];
        int col = j + y[k];
        if(isValid(row,col,n))
        {
           int newd = max(val,grid[row][col]);
            if(newd<dist[row][col])
            {
                dist[row][col] = newd;
                pq.push({newd,{row,col}});
            }

        }
    }
    
}


return -1;


    }
};