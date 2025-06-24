class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>ds;

        combRec(res, ds, k, n, 0, 0);
        return res;
    }

    void combRec(vector<vector<int>>&res, vector<int>&ds, int k, int n, int idx, int sum) {
        if(ds.size()>k) return;
        if(ds.size()==k) {
            if(sum==n) {
                res.push_back(ds);
            }
            return;
        }

        for(int i = idx+1; i<10; i++) {
            if(sum+i > n) break;
            ds.emplace_back(i);
            combRec(res, ds, k, n, i, sum+i);
            ds.pop_back();
        }
    }
};
