#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {

        ListNode* slow;
        ListNode* fast;
        fast = slow = head;

        while ((fast != nullptr) && (fast->next != nullptr))
        {
            slow = slow->next;
            
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;

        
    }
};

ListNode* buildList(initializer_list<int> vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int v : vals) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy->next;
}

int main() {
    Solution sol;

    ListNode* head1 = buildList({3, 2, 0, -4});
    head1->next->next->next->next = head1->next;
    cout << "Test Case 1:" << endl;
    cout << "List: [3, 2, 0, -4] with cycle at index 1" << endl;
    cout << "Has Cycle: " << (sol.hasCycle(head1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    ListNode* head2 = buildList({1, 2});
    head2->next->next = head2;
    cout << "Test Case 2:" << endl;
    cout << "List: [1, 2] with cycle at index 0" << endl;
    cout << "Has Cycle: " << (sol.hasCycle(head2) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    ListNode* head3 = buildList({1});
    cout << "Test Case 3:" << endl;
    cout << "List: [1] with no cycle" << endl;
    cout << "Has Cycle: " << (sol.hasCycle(head3) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;

    ListNode* head4 = buildList({1, 2, 3, 4, 5});
    cout << "Test Case 4:" << endl;
    cout << "List: [1, 2, 3, 4, 5] with no cycle" << endl;
    cout << "Has Cycle: " << (sol.hasCycle(head4) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;

    return 0;
}