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
    bool isBalanced(TreeNode *node) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (node == NULL) return true;  
        return abs(maxDepth(node->left)-maxDepth(node->right))<=1 && isBalanced(node->left) && isBalanced(node->right);
 
    }
    int maxDepth (TreeNode *node) {
        if (node == NULL) return true;
        return max(maxDepth(node->left),maxDepth(node->right))+1;
    }
};