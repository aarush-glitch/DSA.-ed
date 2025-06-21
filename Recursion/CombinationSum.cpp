class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>>res;
        vector<int>comb;
        makeC(cand, target, 0, res, comb, 0);
        return res;
    }

    void makeC(vector<int>& cand, int t, int idx, vector<vector<int>>& res, vector<int>& comb, int total) {
        if(total==t) {
            res.push_back(comb);
            return;
        }
        if(total>t || idx>=cand.size()) return;
        //pick
        comb.push_back(cand[idx]);
        makeC(cand, t, idx, res, comb, total+cand[idx]);
        comb.pop_back();
        //not pick
        makeC(cand, t, idx+1, res, comb, total);
    }
};
