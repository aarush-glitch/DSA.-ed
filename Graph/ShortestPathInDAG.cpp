// User function Template for C++
class Solution {
  private: 
    void topo(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node]=1;
        for(auto it: adj[node]) {
            int v = it.first;
            if(!vis[v]) {
                topo(v, adj, vis, st);
            }
        }
        
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                topo(i, adj, vis, st);
            }
        }
        
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i] = 1e9;
        dist[0]=0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(dist[node]!=1e9) {
                for(auto it: adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    
                    int totalDist = dist[node] + wt;
                    if(totalDist < dist[v]) dist[v] = totalDist;
                }
            }
        }
        
        for(int i=0; i<V; i++) {
            if(dist[i]==1e9) dist[i] = -1;
        }
        return dist;
    }
};
