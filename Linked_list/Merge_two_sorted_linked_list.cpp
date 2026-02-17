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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr || head2 == nullptr)
        {
            return (head1 == nullptr)? head2 : head1;
        }

        if (head1->val <= head2->val)
        {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }else
        {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
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

    ListNode* head1_1 = buildList({1, 2, 4});
    ListNode* head2_1 = buildList({1, 3, 4});
    cout << "Test Case 1:" << endl;
    cout << "List 1: ";
    printList(head1_1);
    cout << "List 2: ";
    printList(head2_1);
    cout << "Merged: ";
    printList(sol.mergeTwoLists(head1_1, head2_1));
    cout << "Expected: [1, 1, 2, 3, 4, 4]" << endl << endl;

    ListNode* head1_2 = nullptr;
    ListNode* head2_2 = nullptr;
    cout << "Test Case 2:" << endl;
    cout << "List 1: []" << endl;
    cout << "List 2: []" << endl;
    cout << "Merged: ";
    printList(sol.mergeTwoLists(head1_2, head2_2));
    cout << "Expected: []" << endl << endl;

    ListNode* head1_3 = nullptr;
    ListNode* head2_3 = buildList({0});
    cout << "Test Case 3:" << endl;
    cout << "List 1: []" << endl;
    cout << "List 2: ";
    printList(head2_3);
    cout << "Merged: ";
    printList(sol.mergeTwoLists(head1_3, head2_3));
    cout << "Expected: [0]" << endl << endl;

    ListNode* head1_4 = buildList({1, 3, 5});
    ListNode* head2_4 = buildList({2, 4, 6});
    cout << "Test Case 4:" << endl;
    cout << "List 1: ";
    printList(head1_4);
    cout << "List 2: ";
    printList(head2_4);
    cout << "Merged: ";
    printList(sol.mergeTwoLists(head1_4, head2_4));
    cout << "Expected: [1, 2, 3, 4, 5, 6]" << endl;

    return 0;
}