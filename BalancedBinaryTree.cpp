/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int h=0;
        return checkBalanced(root,h);
    }
    
    bool checkBalanced(TreeNode *node,int &height){
        if (node == NULL){
            height = 0;
            return true;
        }
        int lh = 0;
        int rh = 0;
        if (checkBalanced(node->left,lh) == false) return false;
        if (checkBalanced(node->right,rh) == false) return false;
        
        int diff = abs(lh-rh);
        height = max(lh,rh)+1;
        if (diff <= 1) return true;
        else return false;
    }
};
