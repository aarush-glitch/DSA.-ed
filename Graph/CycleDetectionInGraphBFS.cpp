class Solution {
  public:
    bool bfs(int x, vector<vector<int>>&adj, vector<bool>& vis) {
        queue<pair<int, int>> q;
        q.push({x, -1});
        vis[x]=true;
        while(!q.empty()) {
            auto [u, parent] = q.front();
            q.pop();
            for(int v: adj[u]) {
                if(!vis[v]) {
                    q.push({v, u});
                    vis[v]=true;
                }
                else if(v!=parent) {
                    return true;
                }
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(bfs(i, adj, vis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
