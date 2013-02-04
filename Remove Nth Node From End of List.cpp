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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *tailNode = dummy;
        ListNode *frontNode = dummy;
        for (int i=0;i<n;i++) frontNode = frontNode->next;
        while (frontNode->next){
            frontNode = frontNode->next;
            tailNode = tailNode->next;
        }
        tailNode->next =tailNode->next->next;
        return dummy->next;
    }
};
