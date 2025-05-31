class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<int>indexes(n);
        for(int i=0; i<n; i++) indexes[i]=i;
        
        sort(indexes.begin(), indexes.end(), [&end](int a, int b) {
            return end[a]<end[b];
        });
        
        int numMeets=1;
        int lastMeetEnd = end[indexes[0]];
        
        for(int i=1; i<end.size(); i++) {
            if(start[indexes[i]]>lastMeetEnd) {
                numMeets++;
                lastMeetEnd=end[indexes[i]];
            } 
        }
        return numMeets;
    }
};
