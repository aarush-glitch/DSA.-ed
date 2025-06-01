class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=arr.size();
        vector<int>indexes(n);
        for(int i=0; i<n; i++) indexes[i]=i;
        
        sort(indexes.begin(), indexes.end(), [&arr](int a, int b) {
            return arr[a] < arr[b];
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        pq.push(dep[indexes[0]]);

        for(int i=1; i<n; i++) {
            if(arr[indexes[i]] > pq.top()) {
                pq.pop();
            }
            pq.push(dep[indexes[i]]);
        }
        
        return pq.size();
    }
};
