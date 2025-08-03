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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int,int>>> mp;
        traverse(root, 0,0, mp);
        vector<vector<int>> res;
        if(!root) return res;
        for(auto& [x, vert]: mp) {
            res.push_back({});
            for(auto& [y, val]: vert) {
                res.back().push_back(val);
            }
        }
        return res;
    }

    void traverse(TreeNode* root, int x, int y, map<int, multiset<pair<int,int>>>& mp) {
        if(!root) return;
        mp[x].insert({y, root->val});
        traverse(root->left, x-1, y+1, mp);
        traverse(root->right, x+1, y+1, mp);
    }
};
