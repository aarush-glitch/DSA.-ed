class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        subsetR(nums, res, ds, 0);
        //test
        return res;
    }

    void subsetR(vector<int>& nums, vector<vector<int>>& res, vector<int>& ds, int idx) {
        res.push_back(ds);
        for(int i=idx; i<nums.size(); i++) {
            if(i>idx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            subsetR(nums, res, ds, i+1);
            ds.pop_back();
        }
    }
};
