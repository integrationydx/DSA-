class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            int s = flights[i][0];
            int d = flights[i][1];
            int w = flights[i][2];
            adj[s].push_back({d,w});
        }
          priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        pq.push({0,{src,0}});
         while(!pq.empty())
         {
           auto p = pq.top();
            pq.pop();
            int cost = p.first;
            int node = p.second.first;
            int stops = p.second.second;
            if(cost>dist[node][stops]) continue;
            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;

                if(  stops+1<=k+1 && cost + wt<dist[neigh][stops+1])
                {
                     dist[neigh][stops+1] = cost+wt;
                     pq.push({cost+wt,{neigh,1+stops}});
                }
               
            }


            
         }
      int ans = INT_MAX;
      for(int i=0;i<=k+1;i++)
      {
        ans = min(ans,dist[dst][i]);
      }
      if(ans == INT_MAX) return -1;
      return ans;
    }
};