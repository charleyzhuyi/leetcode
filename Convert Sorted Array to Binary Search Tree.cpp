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

    TreeNode *createBalancedBST(vector<int> &num, int left, int right) {
        
        if (left>right) return NULL;
        
        int med = (left + right)/2;
        
        
        TreeNode* leftNode = createBalancedBST(num,left,med-1);
        TreeNode *node = new TreeNode(num.at(med));
        TreeNode* rightNode = createBalancedBST(num,med+1,right);
        
        node->left = leftNode;
        node->right = rightNode;
        
        return node;
        
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.empty()) return NULL;
        
        return createBalancedBST(num,0,num.size()-1);
        
    }
};
