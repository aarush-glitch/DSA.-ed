/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Basically level order traversal but flip some items
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* node = root;
        bool flg=false;
        while(!q.empty()) {
            int sz=q.size();
            vector<int> res;
            for(int i=0; i<sz; i++) {
                TreeNode* temp = q.front();
                q.pop();
                res.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(flg==true) {
                reverse(res.begin(), res.end());
                flg=false;
            }
            else flg=true;
            ans.push_back(res); 
        }
        return ans;
    }
};
