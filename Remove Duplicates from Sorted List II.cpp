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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *prev = dummy;
        ListNode *cur = head;
        
        while (cur!= NULL){
            bool dup = false;
            while (cur->next != NULL && cur->next->val == cur->val){
                dup = true;
                cur = cur->next;
            }
            if (dup){
                prev->next = cur->next;
            }else {
                prev = prev->next;
                
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
