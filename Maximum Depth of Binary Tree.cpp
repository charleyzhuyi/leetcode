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
    
    
    void getmaxDepth(TreeNode *node,int depth,int &max) {
        if (node == NULL) return;
        
        depth++;
        if (depth>max)
            max = depth;
        
        
        getmaxDepth(node->left,depth,max);
        getmaxDepth(node->right,depth,max);
        
        
    }

    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth = 0;
        int max = 0;
        getmaxDepth(root,depth,max);
        return max;
    }
};
