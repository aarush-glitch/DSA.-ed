class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        if(adj.empty() || adj.size()==0) return {};
        int n = adj.size();
        vector<int> vis(n, 0);
        
        queue<pair<int, int>> q;
        
        q.push({src, 0});
        vector<int> ans(n, 1e9);
        ans[src] = 0;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            vis[node.first] = 1;
            
            for(auto v: adj[node.first]) {
                ans[v] = min(ans[v], node.second + 1);
                if(!vis[v]) q.push({v, ans[v]});
            }
        }
        
        for(int i=0; i<n; i++) {
            if(ans[i]==1e9) ans[i] = -1;
        }
        return ans;
    }
};
