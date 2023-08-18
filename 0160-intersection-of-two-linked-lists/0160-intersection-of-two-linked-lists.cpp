/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *list1, ListNode *list2) {
        
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        int l1=0, l2=0;
        while(temp1){
            l1++;
            temp1=temp1->next;
        }
        while(temp2){
            l2++;
            temp2=temp2->next;
        }
        while(l1>l2){
            l1--;
            list1=list1->next;
        }
        while(l2>l1){
            l2--;
            list2=list2->next;
        }
        while(list1!=list2){
            list1=list1->next;
            list2=list2->next;
        }
        return list2;
    }
};