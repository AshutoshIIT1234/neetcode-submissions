/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node handles edge case of deleting the head
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Advance fast by n+1 steps so gap between fast & slow = n
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both until fast hits null
        // slow will be just BEFORE the node to delete
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Delete the nth node from end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        return dummy->next;
    }
};