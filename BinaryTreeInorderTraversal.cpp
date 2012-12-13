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

    void recursiveTravel(TreeNode *node,vector<int> &travel) {
        
        if (node == NULL)
            return;
            
        recursiveTravel(node->left,travel);
        travel.push_back(node->val);
        recursiveTravel(node->right,travel);
        
    }
    
    void iterativeTravel(TreeNode *root,vector<int> &travel) {
        
        stack <TreeNode*> st;
        
        TreeNode* current = root;
        
        while (!st.empty() || current ) {
            
            if (current){
                st.push(current);
                current = current->left;
            }else {
                current = st.top();
                
                travel.push_back(current->val);
                st.pop();
                
                current = current->right;
                
                
            }
            
        }
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> travel;
        
        //recursiveTravel(root,travel);
        iterativeTravel(root,travel);
        
        return travel;
    }
};
