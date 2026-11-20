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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        stack<int> s1;
        stack<int> s2;
        int carry = 0;

        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }

        while(!s1.empty() or !s2.empty()){
            int sum = 0;
            if(!s1.empty()){ sum += s1.top(); s1.pop();}
            if(!s2.empty()){ sum += s2.top(); s2.pop();}

            sum += carry;
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;

            carry = sum/10;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;

    }
};