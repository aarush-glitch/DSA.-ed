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
    TreeNode* insertIntoBST(TreeNode* root1, int val) {
        TreeNode* root = root1;
        TreeNode* newNode = new TreeNode(val);
        if(!root) return newNode;
        while(root) {
            if(root->val > val) {
                if(root->left) root = root->left;
                else {
                    root->left = newNode;
                    return root1;
                }
            }
            else {
                if(root->right) root = root->right;
                else {
                    root->right = newNode;
                    return root1;
                }
            }
        }
        return root1;
    }
};
