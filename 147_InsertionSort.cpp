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
    ListNode* insertionSortList(ListNode* head) {
        // create a dummy node to point to the head of the sorted list
        ListNode dummy(0);
        
        // for each node in the old list (pointed by head), compare with the sorted list pointed by p one by one 
        // find the place to insert it
        while (head) {
            ListNode *p = &dummy;
            while (p && p->next) {
                if (p->next->val < head->val) {
                    p = p->next;
                } else {
                    break;
                }
            }
            
            // insert the node which is less than current p->next
            ListNode *n = p->next;
            p->next = head;
            head = head->next;
            p->next->next = n;
        }
        
        return dummy.next;
    }
};
