/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent, TreeNode* target) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* current = q.front(); q.pop();
            if(current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent, target);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int cur=0;
        while(!q.empty()) {
            int size=q.size();
            if(cur++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = q.front(); q.pop();
                if(current->left && !vis[current->left]) {
                    q.push(current->left);
                    vis[current->left]=true;
                }
                if(current->right && !vis[current->right]) {
                    q.push(current->right);
                    vis[current->right]=true;
                }
                if(parent[current] && !vis[parent[current]]) {
                    q.push(parent[current]);
                    vis[parent[current]]=true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()) {
            TreeNode* current =  q.front(); q.pop();
            res.push_back(current->val);
        }

        return res;
    }
};
