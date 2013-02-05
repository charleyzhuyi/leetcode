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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *sent = new ListNode(0);
        sent->next= head;
        myswap(sent->next,sent);
        return sent->next;
    }
    
    void myswap(ListNode *node,ListNode *prev){
        if (node == NULL || node->next == NULL) return;
        
        ListNode *nextNode = node->next->next;
        prev->next = node->next;
        node->next->next = node;
        node->next = nextNode;
        myswap(nextNode,node);
    }
};
