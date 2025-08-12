class Solution {
  public:
    void dfsUtil(int x, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans) {
        if(vis[x]) return ;
        ans.push_back(x);
        vis[x]=true;
        
        for(int i=0; i<adj[x].size(); i++) {
            if(!vis[adj[x][i]]) dfsUtil(adj[x][i], adj, vis, ans);
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<int> ans;
        if(!V) return ans; 
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsUtil(i, adj, vis, ans);
            }
        }
        return ans;
    }
};
