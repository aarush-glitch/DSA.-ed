/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeVal {
public:
    int maxNode, minNode, maxSize;
    NodeVal(int mn, int mm, int ms) {
        maxNode = mm;
        minNode = mn;
        maxSize = ms;
    }
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeVal helper(Node* root) {
        if(!root) return NodeVal(INT_MAX, INT_MIN, 0);
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        if(left.maxNode < root->data && right.minNode > root->data) {
            return NodeVal(left.minNode, right.maxNode, left.maxSize + right.maxSize + 1);
        }
        return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
    int largestBst(Node *root) {
        // Your code here
        return helper(root).maxSize;
    }
};
