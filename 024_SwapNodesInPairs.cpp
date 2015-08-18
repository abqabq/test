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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        
        while (p->next && p->next->next) {
            // swap
            ListNode* temp = p->next->next;
            p->next->next = temp->next;
            temp->next = p->next;
            p->next = temp;
            
            p = p->next->next;
        }
        
        return dummy.next;
    }
};
