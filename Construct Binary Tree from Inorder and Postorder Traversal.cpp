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

    TreeNode *buildATree(vector<int> &inorder, vector<int> &postorder,int left,int right,int pos){
        
        if (left > right)
            return NULL;
        
        int spliter = postorder[pos];
        vector<int>::iterator iter = find(inorder.begin()+left,inorder.begin()+right,spliter);
        int index = distance(inorder.begin(),iter);
        
        TreeNode *node = new TreeNode(spliter);
        node->right = buildATree(inorder,postorder,index+1,right,pos-1);
        node->left = buildATree(inorder,postorder,left,index-1,pos-1-(right-index));
        
        return node;
        
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildATree(inorder,postorder,0,inorder.size()-1,postorder.size()-1);
        
    }
};
