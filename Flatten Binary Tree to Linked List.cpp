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
