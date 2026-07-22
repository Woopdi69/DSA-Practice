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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;

        int n = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            cur = cur->next;
            n++;
        }

        k %= n;
        cur = head;
        while(k--){
            ListNode* prev = nullptr;
            ListNode* nxt = cur;

            while(cur->next != nullptr){
                prev = cur;
                cur = cur->next;
            }

            prev->next = nullptr;
            cur->next = nxt;
        }

        return cur;
    }
};