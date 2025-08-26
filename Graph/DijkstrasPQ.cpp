// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto& edge:edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        
        dist[src] = 0;
        
        pq.push({0, src});
        
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto [x,y]: adj[node]) {
                int eW = y;
                int adjNode = x;
                
                if(dis+eW < dist[adjNode]) {
                    dist[adjNode] = dis+eW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
