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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* node = head;
        mydeleteDup(node);
        return head;
    }
    void mydeleteDup(ListNode *node) {
        if (node == NULL) return;
        if (node->next == NULL) return;
        while (node->val == node->next->val){
            //delete next node;
            node->next = node->next->next;
            if (!node->next) break;
        }
        mydeleteDup(node->next);
    }
};
