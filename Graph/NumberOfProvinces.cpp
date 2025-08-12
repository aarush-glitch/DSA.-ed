class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int ans=0;
        if(V==0) return ans;
        vector<bool> vis(V, false);
        queue<int> q;
        

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                q.push(i);
                vis[i]=true;

                while(!q.empty()) {
                    int t = q.front();
                    q.pop();
                    for(int j=0; j<V; j++) {
                        if(t!=j && !vis[j] && isConnected[t][j]) {
                            q.push(j);
                            vis[j]=true;
                        }
                    }
                }
                ans++;
            }
        }

        return ans;
    }
};
