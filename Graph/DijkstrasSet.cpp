// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        set<pair<int,int>> st;
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        st.insert({0, src});
        
        while(!st.empty()) {
            auto it = *(st.begin());
            int node= it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto it2: adj[node]) {
                int adjNode = it2.first, eW = it2.second;
                
                if(dis + eW < dist[adjNode]) {
                    //if(dist[adjNode]!=1e9) st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + eW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
