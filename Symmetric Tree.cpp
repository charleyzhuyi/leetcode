/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* recursion solution */ 
class Solution {
public:
    bool isSameTree(TreeNode *nodeA, TreeNode *nodeB){
        if (!nodeA && !nodeB)  return true;
        if ((!nodeA && nodeB) || (nodeA && !nodeB)) return false;
        if (nodeA->val != nodeB->val) {
            return false;
        } else {
            return isSameTree(nodeA->left,nodeB->right) && isSameTree(nodeA->right,nodeB->left);
        }
    }

    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return true;
        return isSameTree(root->left,root->right);
        
    }
};
