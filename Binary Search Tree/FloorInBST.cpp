// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int input) {
        // Code here
        if(!root) return -1;
        int floor = INT_MIN;
        
        while(root) {
            if(root->data==input) return input;
            if(root->data < input) {
                floor = max(root->data, floor);
                root=root->right;
            }
            else root = root->left;
        }
        return floor==INT_MIN?-1:floor;
    }
};
