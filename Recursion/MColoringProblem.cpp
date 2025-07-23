class Solution {
  public:
    bool isSafe(int node, vector<vector<int>>&adj, vector<int>& color, int clr) {
        for(int it: adj[node]) {
            if(color[it]==clr) return false;
        }
        return true;
    }
  
    bool solve(vector<vector<int>>& adj, vector<int>& color, int m, int node) {
        if(node==adj.size()) return true;
        
        for(int i=1; i<=m; i++) {
            if(isSafe(node, adj, color, i)) {
                color[node] = i;
                if(solve(adj, color, m, node+1)==true) return true;
                color[node] = 0;
            }
        }
        return false;
    }
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        vector<int> color(v, 0);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        if(solve(adj, color, m, 0)==true) return true;
        return false;
    }
};
