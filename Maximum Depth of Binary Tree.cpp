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
    int maxDepth(TreeNode *node) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (node == NULL) return 0;
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        return max(left,right)+1;
    }
};
