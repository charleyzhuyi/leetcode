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
    bool result;
    
    void dfsPathSum(TreeNode *node, int sum, int cSum){
        if (node == NULL) return;
        
        cSum = cSum + node->val;
        if (cSum == sum && node->left == NULL && node->right == NULL) {
            result = true;
            return;
        }
        
        dfsPathSum(node->left,sum,cSum);
        dfsPathSum(node->right,sum,cSum);
        
    }

    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result = false;
        
        dfsPathSum(root,sum,0);
        
        return result;
    }
};
