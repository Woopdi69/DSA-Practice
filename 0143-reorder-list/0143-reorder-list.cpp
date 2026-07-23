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
    void reorderList(ListNode* head){
        ListNode* cur = head;
        stack<ListNode* > stk;

        int n = 0;
        while(cur != nullptr){
            n++;
            stk.push(cur);
            cur = cur->next;
        }

        cur = head;
        for(int i = 0; i < n/2; i++){
            ListNode* f = stk.top();
            stk.pop();

            ListNode* s = cur->next;
            cur->next = f;
            f->next = s;

            cur = s;
        }

        cur->next = nullptr;
    }
};