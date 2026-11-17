class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Step 2: Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Step 3: Move both together
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 4: Remove node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        return dummy->next;
    }
};
