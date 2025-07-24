class Solution {
  public:
    vector<int> d = {1, 0, -1, 0}; // row movement: D, R, U, L
    vector<int> dc = {0, 1, 0, -1}; // col movement: D, R, U, L    
    vector<char> vals = {'D', 'R', 'U', 'L'};

    
    bool isSafe(vector<vector<int>>& maze, vector<vector<bool>>& vis, int r, int c) {
        if(r<0 || c<0 || r>=maze.size() || c>=maze[0].size()) return false;
        return maze[r][c] && !vis[r][c];
    }
    
    void solve(vector<vector<int>>& maze, string path,vector<string>& res, vector<vector<bool>>& vis, int r, int c) {
        if(r==maze.size()-1 && c==maze.size()-1) {
            res.push_back(path);
            return ;
        }
        
        for(int i=0; i<4; i++) {
            int nr = r+d[i];
            int nc = c+dc[i];
            if(isSafe(maze, vis, nr, nc)) {
                vis[nr][nc]=true;
                path+=vals[i];
                solve(maze, path, res, vis, nr, nc);
                path.pop_back();
                vis[nr][nc]=false;
            }
        }
        
    }
    
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> result;
        int n=maze.size();
        if(n==0 || maze[0][0]==0) return result;
        
        
        vector<vector<bool>> vis(n,vector<bool>(n, false));
        string path;
        vis[0][0]=true;
        solve(maze, path, result, vis, 0, 0);
        
        
        sort(result.begin(), result.end());
        return result;
    }
};
