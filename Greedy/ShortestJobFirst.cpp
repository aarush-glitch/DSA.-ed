// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        
        int wt=0, sum=0, n=bt.size();
        for(int i=0; i<n; i++) {
            sum+=wt;
            wt+=bt[i];
        }
        
        return (long long)sum/n;
    }
};
