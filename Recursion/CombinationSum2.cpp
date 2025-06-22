class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        vector<vector<int>>res;
        vector<int>ds;
        sumC(cand, target, 0, res, ds);
        return res;
    }

    void sumC(vector<int>& cand, int t, int i, vector<vector<int>>& res, vector<int>& ds) {
        if(t==0) {
            res.push_back(ds);
            return;
        }
        if(i>=cand.size() || t<0) return;

        for(int j=i; j<cand.size(); j++) {
            if(j>i && cand[j]==cand[j-1]) continue;
            ds.push_back(cand[j]);
            sumC(cand, t-cand[j], j+1, res ,ds);
            ds.pop_back();
        }
    }
};
