// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int n = arr.size();
        queue<pair<int, int>> q;
        q.push({0, start});
        
        while(!q.empty()) {
            auto [d, num] = q.front();
            q.pop();
            if(num==end) return d;
            for(int i=0; i<n; i++) {
                int mul = (num*arr[i])%100000;
                if(dist[mul] > d+1) {
                    dist[mul] = d+1;
                    q.push({d+1, mul});
                }
                
            }
        }
        return dist[end]==1e9?-1: dist[end];
    }
};
