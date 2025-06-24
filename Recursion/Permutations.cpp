class Solution {
public:
    void solve(vector<vector<int>>&res, vector<int>&nums, int idx) {
        if(idx==nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[i], nums[idx]);
            solve(res, nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        solve(res, nums, 0);
        return res;
    }
};
