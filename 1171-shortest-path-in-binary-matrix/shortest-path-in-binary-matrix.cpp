class Solution {
public:
bool valid(int i, int j, int n, int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();


        vector<vector<int>> res(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

       int x[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int y[8] = {-1,  0,  1, -1, 1,-1, 0, 1};

        res[0][0] = 1;
        pq.push({1,{0,0}});

         while(!pq.empty())
         {
           auto p = pq.top();
           pq.pop();
           int dist  = p.first;
           int row = p.second.first;
           int col = p.second.second;

           
            if(dist > res[row][col])
                continue;

                for(int k=0;k<8;k++)
                {
                    int r = x[k] + row;
                    int c = y[k] + col;
                    if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

                    if(valid(r,c,n,m) == 0) continue;
                    if(grid[r][c] == 1) continue;
                    if(dist + 1 < res[r][c])
                    {
                        res[r][c] = dist + 1;
                        pq.push({dist + 1, {r, c}});
                    }


                }

         }
         if(res[n-1][m-1] == INT_MAX)  return -1;     
         return res[n-1][m-1];
    }
};