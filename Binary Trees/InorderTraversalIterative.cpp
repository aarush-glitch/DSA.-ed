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

// 1
// 2 3
// 4 5 6 7

// // 4 2 5 1 6 3 7
// since inorder we can say 
// inorder(r->left)
// print(r)
// inorder(r->right)

// keep left and keep pushing to stack
// when left ends
// print node make node right
// if node null we carry with queue 


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> q;
        vector<int> ans;
        TreeNode* node = root;
        while(!q.empty() || node!=nullptr) {
            while(node!=nullptr) {
                q.push(node);
                node=node->left;
            }
            node=q.top();
            q.pop();
            ans.push_back(node->val);
            node = node->right;
        }

        return ans;
    }
};
