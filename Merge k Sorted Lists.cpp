/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct Compare {
    bool operator ()(const ListNode* a, const ListNode* b) {
  	return a->val > b->val;
	}
};

class Solution {
public:
    /* time is O(logk*n) where n is total number of elements in all lists
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
        
        for (int i=0;i<lists.size();i++) {
            if (lists[i] != NULL) {
                min_heap.push(lists[i]);
            }
        }
        
        ListNode *head = new ListNode(0);
        ListNode *myNode = head;
        
        while ( !min_heap.empty()) {
            
            ListNode *minNode = min_heap.top();
            min_heap.pop();
            
            if (minNode->next != NULL)
                min_heap.push(minNode->next);
            
            ListNode *aNode = minNode;
            myNode->next = aNode;
            myNode = myNode->next;
        }
        
        return head->next;
        
    }
};
