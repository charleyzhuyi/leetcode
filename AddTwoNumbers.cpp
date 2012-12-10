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
   ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *headNode = new ListNode(0);
        ListNode *node = headNode;
        
        if (l1 == NULL)
            return NULL;
        else if (l2 == NULL)
            return NULL;
        
        int carry = 0;
        if (l1->val + l2->val >=10){
            node->val = l1->val + l2->val - 10;
            carry = 1;
        } else {
            node->val = l1->val + l2->val;
        }
        
        
        while (l1->next != NULL || l2->next != NULL) {
            
            int aVal;
            if (l1->next == NULL)
                aVal = 0;
            else
                aVal = l1->next->val;
                
            int bVal;
            if (l2->next == NULL)
                bVal = 0;
            else
                bVal = l2->next->val;
            
            int sum = aVal +bVal + carry;
            
            carry = 0;
            while (sum >= 10) {
                sum -= 10;
                carry++;
            }
            
            if (node->next == NULL)
                node -> next = new ListNode(0);
            node->next->val = sum;
           
            node = node -> next;
            if (l1->next)
                l1 = l1 -> next;
            if (l2->next)
                l2 = l2 -> next;
            
        }
        
      
        
        if (carry != 0) {
             if (node->next == NULL)
                node -> next = new ListNode(0);
            node->next->val = carry;
        }
        
        return headNode;
    }
};