// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,int>> ratio;
        int n = val.size();
        for(int i=0; i<n; i++) {
            ratio.push_back({val[i]*1.0/wt[i], i});
        }
        
        sort(ratio.begin(), ratio.end(), [](const pair<double,int>& a, const pair<double,int>& b) {
            return a.first>b.first;
        });
        
        double result=0.0;
        int i=0;
        while(capacity>0 && i<n) {
            if(wt[ratio[i].second]<capacity) {
                result+=val[ratio[i].second];
                capacity-=wt[ratio[i].second];
                i++;
            }
            else {
                result+=ratio[i].first*capacity;
                capacity=0;
            }
        }
        
        return result;
    }
};
