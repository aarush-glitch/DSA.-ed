/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve(Node* root, int key, Node*& minVal) {
        while(root) {
        if(root->data <= key) root = root->right;
        else {
            if(!minVal) minVal=root;
            else if(root->data < minVal->data) minVal = root;
            root = root->left;
        }
        }
        return;
    }
    void solve2(Node* root, int key, Node*& minVal) {
        while(root) {
        if(root->data >= key) root = root->left;
        else {
            if(!minVal) minVal = root;
            else if(root->data > minVal->data) minVal = root;
            root = root->right;
        }}
        return ;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* node = root;
        Node* minRoot = nullptr;
        solve(node, key, minRoot);
        Node* maxRoot = nullptr;
        solve2(root, key, maxRoot);
        
        return {maxRoot, minRoot};
    }
};
