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
    TreeNode* solve(vector<int>& preorder, int minVal, int maxVal, int &i) {
        if(i>=preorder.size()) return nullptr;

        if(preorder[i] < minVal || preorder[i] > maxVal) return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = solve(preorder, minVal, root->val, i);
        root->right = solve(preorder, root->val, maxVal, i);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder, INT_MIN, INT_MAX, i);
    }
};
