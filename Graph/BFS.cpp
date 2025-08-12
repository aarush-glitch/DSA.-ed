class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int V = adj.size();
        vector<int> ans;
        if(!V) return ans; 
        vector<bool> vis(V, false);
        
        queue<int> q;
        q.push(0);
        vis[0]=true;
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(int i=0; i<adj[t].size(); i++) {
                if(!vis[adj[t][i]]) {
                    q.push(adj[t][i]);
                    vis[adj[t][i]]=true;
                }
            }
        }
        return ans;
    }
};
