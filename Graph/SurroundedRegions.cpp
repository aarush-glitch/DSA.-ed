class Solution {
public:
    void bfs(int x, int y, vector<vector<char>>& board, vector<vector<int>>& vis) {
        if(vis[x][y]) return ;
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) {
                int u=x+dx;
                int v=y+dy;
                if(u>=0 && u<board.size() && v>=0 && v<board[0].size() && board[u][v]=='O' && !vis[u][v]) {
                    q.push({u, v});
                    vis[u][v]=1;
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int j=0; j<n; j++) {
            if(board[0][j]=='O') {
                bfs(0, j, board, vis);
            }
            if(board[m-1][j]=='O') {
                bfs(m-1, j, board, vis);
            }
        }

        for(int i=0; i<m; i++) {
            if(board[i][0]=='O') {
                bfs(i, 0, board, vis);
            }
            if(board[i][n-1]=='O') {
                bfs(i, n-1, board, vis);
            }
        }

        for(int i=1; i<m-1; i++) {
            for(int j=1; j<n-1; j++) {
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};
