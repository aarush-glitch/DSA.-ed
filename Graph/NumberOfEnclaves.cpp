class Solution {
public:
    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(vis[x][y]) return ;
        queue<pair<int,int>> q;
        q.push({x, y});
        vis[x][y]=1;
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()) {
            auto [u, v] = q.front();
            q.pop();

            for(auto [du, dv]: dirs) {
                int i=u+du, j=v+dv;

                if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1 && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            if(!vis[i][0] && grid[i][0]) {
                bfs(i, 0, grid, vis);
            }
            if(!vis[i][n-1] && grid[i][n-1]) {
                bfs(i, n-1, grid, vis);
            }
        }

        for(int j=0; j<n; j++) {
            if(!vis[0][j] && grid[0][j]) {
                bfs(0, j, grid, vis);
            }
            if(!vis[m-1][j] && grid[m-1][j]) {
                bfs(m-1, j, grid, vis);
            }
        }

        int cntEnclaves = 0;
        for(int i=1; i<m-1; i++) {
            for(int j=0; j<n-1; j++) {
                if(grid[i][j] && !vis[i][j]) cntEnclaves++;
            }
        }

        return cntEnclaves;
    }
};
