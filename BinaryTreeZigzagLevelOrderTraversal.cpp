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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > results;
        queue<TreeNode*> q;
        bool direction = false;
        TreeNode *dummy = new TreeNode(0);
        
        if (root == NULL) return results;
        
        q.push(root);
        q.push(dummy);
        
        vector<int> result;
        while (!q.empty()) {
           
            TreeNode *node = q.front();
            
            
            if (node != dummy) {
                
                q.pop();
                
                
                result.push_back(node->val);
               
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
             
            }else {
                
                if (direction)
                    reverse(result.begin(),result.end());
                
                
                q.pop();
                results.push_back(result);
                result.clear();
                q.push(node);
                
                direction?direction = false:direction = true;
            }
            
             if (node == dummy && q.size() == 1) break;
            
             
        }
        
        return results;
            
           
    }
        
    
};
