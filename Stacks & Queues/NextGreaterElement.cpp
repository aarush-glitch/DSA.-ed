class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        unordered_map<int,int>mp;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if(st.empty()) {
                mp[nums2[i]]=-1;
            }
            else mp[nums2[i]]=st.top();


            st.push(nums2[i]);
        }

        vector<int>nge(nums1.size());

        for(int i=0; i<nums1.size(); i++) {
            nge[i]=mp[nums1[i]];
        }

        return nge;
    }
};
