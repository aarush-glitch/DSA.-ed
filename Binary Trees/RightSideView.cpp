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
    void traverse(TreeNode* root, int h, vector<int>& res) {
        if(!root) return ;
        int n=res.size();
        if(h>=n) {
            res.push_back(root->val);
        }
        if(root->right) {
            traverse(root->right, h+1, res);
        }
        if(root->left) {
            traverse(root->left, h+1, res);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        traverse(root, 0, res);

        return res;
    }
};
