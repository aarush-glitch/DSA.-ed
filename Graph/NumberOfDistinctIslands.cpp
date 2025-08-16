// User function Template for C++

// n x m x log(n x m)  +  n x m x 4

class Solution {
  public:
    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& vec) {
        vis[x][y] = 1;
        // vec.push_back({0, 0});
        
        vector<pair<int, int>> dirs = { {1,0}, {0, 1}, {0, -1}, {-1, 0} };
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        
        while(!q.empty()) {
            auto [u, v] = q.front();
            q.pop();
            vec.push_back({u-x, v-y});
            
            for(auto [du, dv]: dirs) {
                int row = u+du, col = v+dv;
                if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]==1) {
                    vis[row][col] = 1;
                    q.push({row, col});
                }
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        int res=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                vector<pair<int, int>> vec;
                if(!vis[i][j] && grid[i][j]==1) {
                    bfs (i, j, grid, vis, vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
