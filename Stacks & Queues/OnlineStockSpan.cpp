class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {}
    
    int next(int price) {
        int counter=1;
        while(!st.empty() && st.top().first <= price) {
            counter+=st.top().second;
            st.pop();
        }
        st.push({price, counter});
        return counter;
    }
};
