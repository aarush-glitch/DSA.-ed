class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        int sum = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, -1}});
        
        vector<int> vis(V, 0);
        vector<vector<int>> eT;
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int eW = it.first;
            auto [node, parent] = it.second;
            if(vis[node]) continue;
            
            eT.push_back({parent, node, eW});
            sum+=eW;
            vis[node] = 1;
            for(auto it: adj[node]) {
                if(!vis[it.first]) {
                    pq.push({it.second, {it.first, node}});
                }
            }
        }
        
        return sum;
    }
};
