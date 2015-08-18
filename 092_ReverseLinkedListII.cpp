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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) {
            return head;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        
        // find the pre-M node
        n -= m;
        ListNode *p = &dummy;
        while(--m) {
            p = p->next;
        }
        
        // reverse nodes from M to N
        ListNode *p1 = p->next;
        ListNode *p2 = p1->next;
        while(n--){
            p1->next = p2->next;
            p2->next = p->next;
            p->next = p2;
            p2 = p1->next;
        }
        
        return dummy.next;
    }
};
