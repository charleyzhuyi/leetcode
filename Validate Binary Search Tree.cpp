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
    bool isValidBSTHelper(TreeNode *node,int min, int max){
        if (node == NULL) return true;
        
 
        return node->val < max && node->val > min 
                && isValidBSTHelper(node->left,min,node->val)
                && isValidBSTHelper(node->right,node->val,max);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root==NULL) return true;
        return isValidBSTHelper(root,INT_MIN,INT_MAX);
    }
};
