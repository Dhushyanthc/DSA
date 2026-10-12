class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        
        for (int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            while (curr != nullptr) {
                min_heap.push(curr->val);
                curr = curr->next;
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while (!min_heap.empty()) {
            tail->next = new ListNode(min_heap.top());
            min_heap.pop();
            tail = tail->next;
        }
        
        return dummy->next;
    }
};
