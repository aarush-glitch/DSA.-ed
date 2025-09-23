class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        using ll = long long;
        const ll INF = 4e18;  // large enough to avoid overflow

        // adjacency list
        vector<vector<pair<int, ll>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1];
            ll w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // distance + ways
        vector<ll> dist(n, INF);
        vector<ll> ways(n, 0);

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d > dist[u]) continue; // skip stale entries

            for (auto& [v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (d + w == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return (int)(ways[n - 1] % MOD);
    }
};
