// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V, 1e8);
        dist[src] = 0;
        bool flg=false;
        for(int i=0; i<=V; i++) {
            for(auto it: edges) {
                int u = it[0], v = it[1], wt = it[2];
                if(dist[u]!=1e8 && dist[u] + wt < dist[v]) {
                    if(i==V) {
                        flg = true;
                        break;
                    }
                    dist[v] = dist[u]+wt;
                }
            }
        }
        if(flg==true) {
            return {-1};
        }
        return dist;
    }
};
