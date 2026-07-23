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
private:
    ListNode* merge(ListNode* &l1, ListNode* &l2){
        ListNode* head = new ListNode(0);
        ListNode* ans = head;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val > l2->val){
                head->next = l2;
                l2 = l2->next;
            }else{
                head->next = l1;
                l1 = l1->next;
            }

            head = head->next;
        }

        while(l1 != nullptr){
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }

        while(l2 != nullptr){
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }

        l1 = ans->next;
        delete ans;

        return l1;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return {};
        
        int k = lists.size();
        while(k > 1){
            for(int i = 0; i < k/2; i++){
                lists[i] = merge(lists[i], lists[k-i-1]);
            }
            k = (k+1)/2;
        }

        return lists[0];
    }
};