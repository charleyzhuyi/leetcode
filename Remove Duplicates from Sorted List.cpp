/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*iteration */
 class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *node = head;
        if (node == NULL) return head;
        if (node->next == NULL) return head;
        while (node->next){
            if (node->next->val == node->val){
                //delete next node;
                node->next = node->next->next;
            }else {
                node = node->next;
            }
        }
        return head;
    }
};

 /* recursion */
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
