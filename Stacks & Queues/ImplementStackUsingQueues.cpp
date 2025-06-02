class MyStack {
public:
    queue<int>q;
    MyStack() {
    }
    
    void push(int x) {
        queue<int>st2;
        st2.push(x);
        while(!q.empty()) {
            st2.push(q.front());
            q.pop();
        }
        q.swap(st2);
    }
    
    int pop() {
        if(q.empty()) {
            return -1;
        }
        int ele=q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
