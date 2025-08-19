class Solution {
public:
    bool dfs(int x, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res) {
        vis[x]=2;

        for(auto it: adj[x]) {
            if(vis[it]==2) return true;
            if(!vis[it]) {
                if(dfs(it, adj, vis, res)) return true;
            }
        }
        res.push_back(x);
        vis[x]=1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> ans;
        if(!V) return ans;

        vector<int> vis(V);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, graph, vis, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
