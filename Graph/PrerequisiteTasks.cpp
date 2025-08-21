class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<vector<int>> adj(N);
        for(auto [u, v]: prerequisites) {
            adj[u].push_back(v);
        }
        
        vector<int> indegree(N);
        
        for(int i=0; i<N; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<N; i++) {
            if(!indegree[i]) q.push(i);
        }
        int cnt = 0;    
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(cnt==N) return true;
        return false;
    }
};
