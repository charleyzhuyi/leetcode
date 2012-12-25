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
    void getminDepth(TreeNode *node,int pDepth,int& min){
        if (node == NULL) return;
        
        int myDepth = pDepth + 1;
        
        if (node->left == NULL && node->right == NULL) {
            if (myDepth < min)
                min = myDepth;
        }
        
        getminDepth(node->left,myDepth,min);
        getminDepth(node->right,myDepth,min);
        
    }

    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        
        int minResult = INT_MAX;
        getminDepth(root,0,minResult);
        
        return minResult;
    }
};
