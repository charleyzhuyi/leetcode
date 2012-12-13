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

    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > results;
        queue<TreeNode*> q;
        if (root == NULL) return results;
        
        TreeNode *dummy = new TreeNode(0);  
        q.push(root);
        q.push(dummy);    
        vector <int> result;
        
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node != dummy) {
                result.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            } else {
                q.push(node);
                results.push_back(result);
                result.clear();
                
            }
            if (q.size() == 1 && node == dummy) break;
        } 
        return results;
    }
};
