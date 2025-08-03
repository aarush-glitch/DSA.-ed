/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        map<int, int> mp;
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            if(mp.find(it.first)==mp.end()) {
                mp.insert({it.first, it.second->data});
            }
            if(it.second->left) {
                q.push({it.first-1, it.second->left});
            }
            if(it.second->right) {
                q.push({it.first+1, it.second->right});
            }
        }
        
        for(auto it: mp) {
            res.push_back(it.second);
        }
        return res;
    }
};
