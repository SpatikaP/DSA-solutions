/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int total=0;
    void findPath(TreeNode* root, int targetSum, long sum, unordered_map<long,int> mp){
        if(!root) return;
        sum+=root->val; 
        if(mp.find(sum-targetSum)!=mp.end()){
            total+=mp[sum-targetSum];
        }
        mp[sum]++;
        findPath(root->left,targetSum,sum,mp);
        findPath(root->right,targetSum,sum,mp);
        mp[sum]--;
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        unordered_map<long,int> mp;
        mp[0]=1;
        findPath(root,targetSum,0,mp);
        return total;
    }
};