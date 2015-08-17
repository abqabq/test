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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // dummy node for new head
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        
        // get list length
        int len = 0;
        for (len = 0; fast->next != NULL; len++) {
            fast = fast->next; 
        }
        
        // Get the len - n % len th node
        for (int i = len - k % len; i > 0; i--) {
            slow = slow->next;
        }
        
        // rotate
        fast->next = head;
        dummy.next = slow->next;
        slow->next = NULL;
        
        return dummy.next;
    }
};
