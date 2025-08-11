
class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<vector<int>>& res, int idx) {
        vector<int> ans;
        
        stack<int> st;
        st.push(idx);
        vis[idx]=1;
        
        while(!st.empty()) {
            int t = st.top();
            st.pop();
            ans.push_back(t);
            
            for(int i=0; i<adj[t].size(); i++) {
                if(!vis[adj[t][i]]) {
                    st.push(adj[t][i]);
                    vis[adj[t][i]]=1;
                }
            }
        }
        res.push_back(ans);
        
    }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> vis(V, 0);
        
        vector<vector<int>> adj(V);
        
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> res;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(adj, vis, res, i);
            }
        }
        
        return res;
    }
};
