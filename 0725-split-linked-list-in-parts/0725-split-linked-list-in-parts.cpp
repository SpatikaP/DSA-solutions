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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp=head;
        int c=0;
        while(temp){
            c++;
            temp=temp->next;
        }
        int elements = c/k;
        int extra = c%k;
        
        temp=head;
        
        while(temp){
            
            ans.push_back(temp);
            int curr_len=1;
            
            while(curr_len<elements){
                temp=temp->next;
                curr_len++;
            }
            if(extra>0 && c>k){
                temp=temp->next;
                extra--;
            }
            
            ListNode* x = temp->next;
            temp->next=NULL;
            temp=x;
        }
        while(c<k){
            ans.push_back(NULL);
            c++;
        }
        return ans;
    }
};