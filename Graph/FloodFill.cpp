class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> ans = image;
        if(image[sr][sc]==color) return ans;
        queue<pair<int,int>> q;
        int c = image[sr][sc];

        q.push({sr, sc});
        ans[sr][sc]=color;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) {
                int i=x+dx, j=y+dy;
                if(i>=0 && i<m && j>=0 && j<n && ans[i][j]==c) {
                    q.push({i,j});
                    ans[i][j]=color;
                }
            }
        }
        return ans;
    }
};
