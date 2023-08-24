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
    ListNode* deleteMiddle(ListNode* h) {
        if(!h->next) return NULL;
        ListNode* slow=h;
        ListNode* fast=h->next->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        return h;
    }
};