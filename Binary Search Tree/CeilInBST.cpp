/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    if(!root) return -1;
    int ceil = INT_MAX;
    
    while(root) {
        if(root->data==input) return input;
        if(root->data > input) {
            ceil = min(root->data, ceil);
            root=root->left;
        }
        else root = root->right;
    }
    return ceil==INT_MAX?-1:ceil;
}
