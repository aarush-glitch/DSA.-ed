class Solution {
public:
    bool isSafe(vector<string>&board, int row, int col, int n) {
        int r=row, c=col;
        while(c>=0 && r>=0) {
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=row, c=col;
        while(c>=0) {
            if(board[r][c]=='Q') return false;
            c--;
        }
        c=col;
        while(c>=0 && r<n) {
            if(board[r][c]=='Q') return false;
            c--; r++;
        }
        return true;
    }

    void solve(vector<vector<string>>&res, vector<string>&board, int n, int col) {
        if(col==n) {
            res.push_back(board);
            return;
        }

        for(int row=0; row<n; row++) {
            if(isSafe(board, row, col, n)) {
                board[row][col]='Q';
                solve(res, board, n, col+1);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) {
            board[i]=s;
        }

        solve(res, board, n, 0);
        return res;
    }
};
