/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    TreeNode *createBST(ListNode *&list, int left, int right) {
        
        if (left > right) return NULL;
        
        int med = (left+right)/2;
        
        TreeNode *leftNode = createBST(list,left,med-1);
        
        TreeNode *pNode = new TreeNode(list->val);
         pNode->left = leftNode;
        
       list = list->next;
        
        
        
        TreeNode *rightNode = createBST(list,med+1,right);
        pNode->right = rightNode;
        
        return pNode;
        
    }
    

    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        
        ListNode *list = head;
        
        int length = 1;
        while (list->next != NULL) {
            length++;
            list = list->next;
        }
        
       
        
        return createBST(head,0,length-1);
    }
};
