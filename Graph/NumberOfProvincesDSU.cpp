class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) {
            parent[i]=i;
        }
    }
    
    int findPar(int node) {
        if(parent[node]==node) return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        
        if(ulp_u==ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        DisjointSet ds(V);

        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j]) {
                    ds.unionBySize(i, j);
                }
            }
        }

        int ans = 0;
        for(int i=0; i<V; i++) {
            if(ds.parent[i]==i) ans++;
        }

        return ans;
    }
};
