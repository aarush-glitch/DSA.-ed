// User function Template for C++
class DisjointSet {
    vector<int> parent, size;
public:
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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> ed;
        
        for(int i=0; i<edges.size(); i++) {
            ed.push_back({edges[i][2], edges[i][0], edges[i][1]});
        }
        DisjointSet ds(V);
        sort(ed.begin(), ed.end());
        
        int mstWt = 0;
        
        for(auto it: ed) {
            int wt = it[0];
            int u = it[1];
            int v = it[2];
            
            if(ds.findPar(u)!=ds.findPar(v)) {  // not same component
                mstWt +=wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstWt;
    }
};
