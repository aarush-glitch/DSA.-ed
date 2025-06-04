class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n);
        stack<int>st;

        for(int i=2*n-1; i>=0; i--) {
            int idx = i%n;
            while(!st.empty() && nums[idx]>=st.top()) {
                st.pop();
            }

            if(i==idx) {
                if(st.empty()) {
                    nge[i]=-1;
                }
                else nge[i]=st.top();
            }
            st.push(nums[idx]);
        }
        return nge;
    }
};
