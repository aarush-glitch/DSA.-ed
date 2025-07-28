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
    int height(TreeNode* root) {
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);

        if(left==INT_MAX || right==INT_MAX) return INT_MAX;
        return (abs(left-right)>1?INT_MAX: max(left, right) + 1);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(height(root)==INT_MAX) return false;
        return true;
    }
};
