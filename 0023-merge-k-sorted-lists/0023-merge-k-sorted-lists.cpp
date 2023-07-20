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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy= new ListNode(0);
        ListNode* ans=dummy;
        vector<int> res;
        for(auto e:lists){
            while(e!=NULL){
                res.push_back(e->val);
                e=e->next;
            }
        }
        sort(res.begin(),res.end());
        for(int i=0; i<res.size(); i++){
            ListNode* f = new ListNode(res[i]);
            ans->next=f;
            ans=ans->next;
        }
        return dummy->next;
    }
};