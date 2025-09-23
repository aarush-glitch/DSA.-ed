class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(flights.size()==0) return -1;

        vector<vector<pair<int, int>>> adj(n);
        for(auto& flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> price(n, 1e9);
        price[src] = 0;

        queue<pair<int, pair<int, int>>> pq;//k, price, n
        pq.push({0, {0, src}});

        while(!pq.empty()) {
            if(pq.front().first>k) return price[dst]==1e9?-1: price[dst];

            auto it=pq.front(); pq.pop();

            int kCur=it.first;
            auto [prc, num] = it.second;

            for(auto [i, p]: adj[num]) {
                if(price[i] > (p+prc)) {
                    price[i] = p+prc;
                    if(i!=dst) pq.push({kCur+1, {price[i], i}});
                }
            }
        }
        return price[dst]==1e9?-1: price[dst];
    }
};
