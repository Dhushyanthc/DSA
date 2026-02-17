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
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr) return nullptr;

        if (head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        
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

void printList(ListNode* head) {
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    ListNode* head1 = buildList({1, 2, 3, 4, 5});
    cout << "Test Case 1:" << endl;
    cout << "Input:    ";
    printList(head1);
    cout << "Reversed: ";
    printList(sol.reverseList(head1));
    cout << "Expected: [5, 4, 3, 2, 1]" << endl << endl;

    ListNode* head2 = buildList({1, 2});
    cout << "Test Case 2:" << endl;
    cout << "Input:    ";
    printList(head2);
    cout << "Reversed: ";
    printList(sol.reverseList(head2));
    cout << "Expected: [2, 1]" << endl << endl;

    ListNode* head3 = buildList({1});
    cout << "Test Case 3:" << endl;
    cout << "Input:    ";
    printList(head3);
    cout << "Reversed: ";
    printList(sol.reverseList(head3));
    cout << "Expected: [1]" << endl << endl;

    ListNode* head4 = nullptr;
    cout << "Test Case 4:" << endl;
    cout << "Input:    []" << endl;
    cout << "Reversed: ";
    printList(sol.reverseList(head4));
    cout << "Expected: []" << endl;

    return 0;
}