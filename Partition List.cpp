/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* node = newHead;
        ListNode* locNode = NULL;
        
        while (node->next != NULL){
            if (node->next->val >= x){
                if (locNode == NULL)
                    locNode = node;
                
                node = node->next;
                
            } else {
                if (locNode){
                    //remove next node from linked list
                    ListNode* tmpNode = node->next;
                    node->next = tmpNode->next;
                    
                    //then insert it after locNode
                    tmpNode->next = locNode->next;
                    locNode->next = tmpNode;
                    
                    //move locNode by one
                    locNode = locNode -> next;
                    
                }else {
                    node = node->next;
                }
            }
            
        }
        
        return newHead->next;
    }
};
