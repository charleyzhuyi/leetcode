/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* preorder(TreeNode *node) {
        
        if (node == NULL) return NULL;
        
        if (!node->left && !node->right) return node;
        //Preorder 
        
        //
        TreeNode *lastleft = preorder(node->left);
        TreeNode *lastright = preorder(node->right);
        
        if (lastleft && lastright) {
            lastleft->right = node->right;
            node->right = node->left;
            node->left = NULL;
            return lastright;
        }
        
        if (lastleft) {
            
            node->right = node->left;
            node->left = NULL;
            return lastleft;
            
        }
        
        if (lastright) {
            node->left = NULL;
            return lastright;
        }
        
    }

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        preorder(root);
    }
};

//solution 2
class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        TreeNode *cur = new TreeNode(0);
        myflatten(root,cur);
        
        TreeNode *node = root;
        while (node != NULL){
            node->right = node->left;
            node->left = NULL;
            node = node->right;
        }
        
    }
    void myflatten(TreeNode *node, TreeNode *&current){
        current = node;
        
        if (node->left){
            myflatten(node->left,current);
        }
        
        if (node->right) {
            current->left = node->right;
            node->right = NULL;
            myflatten(current->left,current);
        }
    }

};
