class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> adj(26);
        vector<bool> present(26, false);
        
        for(auto& word: words) {
            for(char ch: word) {
                present[ch-'a']=true;
            }
        }
        int N=0;
        for(int i=0; i<26; i++) {
            if(present[i]) N++;
        }
        
        for(int i=0; i<words.size()-1; i++) {
            int s1 = words[i].size();
            int s2 = words[i+1].size();
            int u=0;
            bool found=false;
            while(u<s1 && u<s2) {
                if(words[i][u] != words[i+1][u]) {
                    adj[words[i][u]-'a'].push_back(words[i+1][u]-'a');
                    found=true;
                    break;
                }
                u++;
            }
            if(!found && s1>s2) return "";
        }
        vector<int> indegree(26);
        
        for(int i=0; i<26; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<26; i++) {
            if(indegree[i]==0 && present[i]) q.push(i);
        }
        
        string topo = "";
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo += (char)(node+'a');
            
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(topo.size()==N) return topo;
        return "";
    }
};
