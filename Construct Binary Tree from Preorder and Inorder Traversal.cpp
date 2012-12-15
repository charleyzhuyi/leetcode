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

    TreeNode *buildATree(vector<int> &inorder, vector<int> &preorder,int left,int right,int pos){
        
        if (left > right)
            return NULL;
        
        int spliter = preorder[pos];
        vector<int>::iterator iter = find(inorder.begin()+left,inorder.begin()+right,spliter);
        int index = distance(inorder.begin(),iter);
        
        TreeNode *node = new TreeNode(spliter);
        
        node->left = buildATree(inorder,preorder,left,index-1,pos+1);
        
        node->right = buildATree(inorder,preorder,index+1,right,pos+1+(index-left));
        
        return node;
        
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         return buildATree(inorder,preorder,0,inorder.size()-1,0);
    }
};


  
