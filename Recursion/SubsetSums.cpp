class Solution {
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        subSum(arr, res, 0, 0);
        sort(res.begin(), res.end());
        return res;
    }
    
    void subSum(vector<int>& arr, vector<int>& res, int sum, int idx) {
        if(idx==arr.size()) {
            res.push_back(sum);
            return;
        }
        
        //nonPick
        subSum(arr, res, sum, idx+1);
        //pick
        subSum(arr, res, sum+arr[idx], idx+1);
    }
};
