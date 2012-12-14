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

    int getMaxSum(TreeNode *node, int& maxSum) {
        
        if (node == NULL) return 0;
        
        int left = getMaxSum(node->left,maxSum);
        int right = getMaxSum(node->right,maxSum);
        
        int localSum = node->val;
        if (left>0)
            localSum += left;
        if (right>0)
            localSum += right;
        
        maxSum = max(maxSum,localSum);
        
        return max(node->val,max(node->val+left,node->val+right));
    }


    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxSum = root->val;
        getMaxSum(root,maxSum);
        
        return maxSum;
    }
};
