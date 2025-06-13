class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if(mat.empty() || mat[0].empty()) return 0;

        int n = mat.size(), m=mat[0].size();
        vector<int> heights(m+1, 0);
        int maxArea=0;

        for(const auto& r: mat) {
            for(int i=0; i<m; i++) {
                heights[i] = (r[i]=='1')? heights[i] + 1: 0;
            }

            stack<int>st;
            for(int i=0; i<m+1; i++) {
                while(!st.empty() && heights[i] < heights[st.top()]) {
                    int h  = heights[st.top()];
                    st.pop();
                    int w = st.empty() ? i : i-st.top()-1;
                    maxArea = max(maxArea, h*w);
                }
                st.push(i);
            }
        }
        return maxArea;
    }
};
