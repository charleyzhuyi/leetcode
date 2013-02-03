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
    void myConnectStepOne(TreeLinkNode *node){
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL) return;
        node->left->next = node->right;
        node->right->next = (node->next)?node->next->left:NULL;
        myConnectStepOne(node->left);
        myConnectStepOne(node->right);
    } 
};
