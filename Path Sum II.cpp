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

    vector<vector<int> >resultPaths;
    void dfsPathSum(TreeNode *node, int sum, int cSum,vector<int> aPath){
        
        if (node == NULL) return;
        
        vector<int> cPath (aPath);
        cPath.push_back(node->val);
        
        cSum = cSum + node->val;
        if (cSum == sum && node->left == NULL && node->right == NULL) {
            resultPaths.push_back(cPath);
            return;
        }
        
        
        dfsPathSum(node->left,sum,cSum,cPath);
        dfsPathSum(node->right,sum,cSum,cPath);
        
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        resultPaths.clear();
        
        vector<int> aPath;
        dfsPathSum(root,sum,0,aPath);
        
        return resultPaths;
    }
};
