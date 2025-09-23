class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!pq.empty()) {
            auto it = pq.top();
            int wt = it.first;
            auto [x, y] = it.second;
            pq.pop();
            if(x==n-1 && y==m-1) return wt;
            for(auto [dx, dy]: dirs) {
                int nx = x+dx, ny = y+dy;
                if(nx>=0 && nx<n && ny>=0 && ny<m) {
                    int newEffort = max(wt, abs(heights[x][y]-heights[nx][ny]));
                    if(dist[nx][ny] > newEffort) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};
