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
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast->next != nullptr){
                fast = fast->next;
            }
        }

        fast = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        while(slow != nullptr){
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }

        slow = prev;

        while(slow != nullptr && fast != nullptr){
            if(slow->val != fast->val){
                return false;
            }

            slow = slow->next;
            fast = fast->next;
        }

        if(slow != nullptr) return false;
        return true;
    }
};