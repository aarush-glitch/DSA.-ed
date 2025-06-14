class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int top=0, bottom=n-1;
        
        while(top<bottom) {
            if(mat[top][bottom]) top++;
            else if(mat[bottom][top]) bottom--;
            else top++, bottom--;
        }
        
        for(int i=0; i<n; i++) {
            if(mat[top][i] && top!=i) return -1;
            if(!mat[i][top]) return -1;
        }
        return top;
    }
};
