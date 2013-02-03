/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        root->next = NULL;
        myConnectStepOne(root);
    }
    TreeLinkNode *findsblingNode(TreeLinkNode *node){
        if (!node) return NULL;
        if (node->left) return node->left;
        if (node->right) return node->right;
        return findsblingNode(node->next);
    }
    void myConnectStepOne(TreeLinkNode *node){
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL) return;
        
        if (node->left && !node->right){
            node->left->next = findsblingNode(node->next);
        } else if (!node->left && node->right){
            node->right->next =findsblingNode(node->next);
        } else {
            node->left->next = node->right;
            node->right->next = findsblingNode(node->next);
        }
        
        /*
            right node must proceed first,
            some leftChildNode->rightChildNode must be eastablished first for correctness.
        */
        myConnectStepOne(node->right); 
        myConnectStepOne(node->left);
       
    } 
};
