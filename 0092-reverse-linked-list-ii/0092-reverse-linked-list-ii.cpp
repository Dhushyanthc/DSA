class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right || left > right) return head;

        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        int count = 1;

        while (count < left) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        ListNode* before = prev;
        ListNode* subHead = curr;

        ListNode* nxt = curr->next;

        while (count < right) {
            ListNode* temp = nxt->next;

            nxt->next = curr;
            curr = nxt;
            nxt = temp;

            count++;
        }

       
        subHead->next = nxt;

        if (before != nullptr) {
            before->next = curr;
        } else {
            head = curr;
        }

        return head;
    }
};