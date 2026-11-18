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
    bool isPalindrome(ListNode* head) {
        vector<int> array;

        ListNode* pointer = head;

        while(pointer != nullptr){
            array.push_back(pointer->val);
            pointer = pointer->next;
        }

        int right = array.size()-1;
        int left = 0;
        while(left < right){
            if(array[left] != array[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
        
    }
};