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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *prev = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        treeWalk(root,prev,first,second);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    void treeWalk(TreeNode *node,TreeNode *&prev,TreeNode *&first,TreeNode *&second){
        if (node == NULL) return;
        treeWalk(node->left,prev,first,second);
        if (prev && node->val < prev->val){
            if (!first) first = prev;
            second = node;
        }
        prev = node;
        treeWalk(node->right,prev,first,second);
    }
};
