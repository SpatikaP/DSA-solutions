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
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* l3 = dummy;
        int carry=0;
        while(l1&&l2){
            int value=l1->val+l2->val+carry;
            carry=value/10;
            l3->next=new ListNode(value%10);
            l3=l3->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int value=l1->val+carry;
            carry=value/10;
            l3->next=new ListNode(value%10);
            l3=l3->next;
            l1=l1->next;
        }
        while(l2){
            int value=l2->val+carry;
            carry=value/10;
            l3->next=new ListNode(value%10);
            l3=l3->next;
            l2=l2->next;
        }
        if(carry){
            l3->next=new ListNode(carry);
        }
        l3=dummy->next;
        return reverse(l3);
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next;
        while(head){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
};