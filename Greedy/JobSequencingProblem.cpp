    class Solution {
      public:
        vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
            // code here
            int n = deadline.size();
            
            vector<pair<int,int>> jobs;
            
            for(int i=0; i<n; i++) {
                jobs.push_back({profit[i], deadline[i]});
            }
            
            sort(jobs.begin(), jobs.end());
            
            int max_deadline = *max_element(deadline.begin(), deadline.end());
            
            vector<bool>timeline(max_deadline, false);
            
            int count=0, total_profit=0;
            int cant_function=INT_MIN;
            for(int i=0; i<n; i++) {
                int d=jobs[i].second, p=jobs[i].first;
                if(d<=cant_function) continue;
                bool flag=true;
                for(int t=min(d, max_deadline)-1; t>=0; t--) {
                    if(!timeline[t]) {
                        timeline[t]=true;
                        count++;
                        total_profit+=p;
                        flag=false;
                        break;
                    }
                }
                if(flag==true) cant_function=max(cant_function, d);
            }
            
            return {count, total_profit};
        }
    };
