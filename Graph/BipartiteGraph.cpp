class Solution {
public:
    bool bfs(int x, vector<vector<int>>& adj, vector<int>& vis) {
        vis[x] = 0;
        queue<int> q;
        q.push(x);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v: adj[u]) {
                if(vis[v]==-1) {
                    vis[v]=!vis[u];
                    q.push(v);
                }
                else if(vis[v]==vis[u]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, -1);

        for(int i=0; i<V; i++) {
            if(vis[i]==-1) {
                if(!bfs(i, adj, vis)) return false;
            }
        }
        return true;
    }
};
