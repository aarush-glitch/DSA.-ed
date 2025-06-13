class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res=0, n=nums.size(), j, k;
        stack<int>st;

        for(int i=0; i<=n; i++) {
            while(!st.empty() && nums[st.top()] > (i==n?-2e9:nums[i])) {
                j=st.top(), st.pop();
                k=st.empty()?-1:st.top();
                res-=(long)nums[j]*(i-j)*(j-k);
            }
            st.push(i);
        }
        st = stack<int>();
        for(int i=0; i<=n; i++) {
            while(!st.empty() && nums[st.top()] < (i==n?2e9:nums[i])) {
                j=st.top(), st.pop();
                k=st.empty()?-1:st.top();
                res+=(long)nums[j]*(i-j)*(j-k);
            }
            st.push(i);
        }
        return res;
    }
};
