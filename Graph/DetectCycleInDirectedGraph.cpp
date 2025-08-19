class Solution {
  public:
    bool dfs(int x, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path) {
        vis[x]=1;
        path[x]=1;
        
        for(auto it: adj[x]) {
            if(path[it]) return true;
            if(!vis[it]) {
                if(dfs(it, adj, vis, path)) return true;
            }
        }
        path[x]=0;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        if(edges.size()==0) return false;
        
        vector<vector<int>> adj(V);
        
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                vector<int> path(V, 0);
                if(dfs(i, adj, vis, path)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
