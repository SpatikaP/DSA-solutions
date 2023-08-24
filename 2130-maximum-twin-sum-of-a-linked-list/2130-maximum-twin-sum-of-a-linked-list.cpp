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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> nums;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int macx=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n/2; i++){
            macx=max(macx,nums[i]+nums[n-i-1]);
        }
        return macx;
    }
};