class Solution {
  public:
  
    int priority(char ch) {
        if(ch=='^') return 3;
        if(ch=='*' || ch=='/') return 2;
        if(ch=='+' || ch=='-') return 1;
        return -1;
    }
    string infixToPostfix(string& s) {
        // code here
        int i=0, n=s.size();
        stack<char>st;
        string ans="";
        
        while(i<n) {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) {
                ans+=s[i];
            }
            else if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')') {
                while(!st.empty() && st.top()!='(') {
                    ans+=st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') st.pop();
            }
            else {
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
