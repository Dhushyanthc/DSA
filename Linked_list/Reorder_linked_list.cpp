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
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while((fast != nullptr) && (fast->next != nullptr))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        ListNode* prev = nullptr;
        ListNode* cur = slow->next;
        slow->next = nullptr;
        
        while (cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;
             prev = cur;
            cur = next;
           
        }
        ListNode* head1 = prev;

        ListNode* first = head;
        ListNode* secondHalf = prev;

        while (secondHalf) {
            ListNode* t1 = first->next;
            ListNode* t2 = secondHalf->next;

            first->next = secondHalf;
            secondHalf->next = t1;

            first = t1;
            secondHalf = t2;
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

    ListNode* head1 = buildList({1, 2, 3, 4});
    cout << "Test Case 1:" << endl;
    cout << "Input:     [1, 2, 3, 4]" << endl;
    sol.reorderList(head1);
    cout << "Reordered: ";
    printList(head1);
    cout << "Expected:  [1, 4, 2, 3]" << endl << endl;

    ListNode* head2 = buildList({1, 2, 3, 4, 5});
    cout << "Test Case 2:" << endl;
    cout << "Input:     [1, 2, 3, 4, 5]" << endl;
    sol.reorderList(head2);
    cout << "Reordered: ";
    printList(head2);
    cout << "Expected:  [1, 5, 2, 4, 3]" << endl << endl;

    ListNode* head3 = buildList({1, 2});
    cout << "Test Case 3:" << endl;
    cout << "Input:     [1, 2]" << endl;
    sol.reorderList(head3);
    cout << "Reordered: ";
    printList(head3);
    cout << "Expected:  [1, 2]" << endl << endl;

    ListNode* head4 = buildList({1});
    cout << "Test Case 4:" << endl;
    cout << "Input:     [1]" << endl;
    sol.reorderList(head4);
    cout << "Reordered: ";
    printList(head4);
    cout << "Expected:  [1]" << endl;

    return 0;
}