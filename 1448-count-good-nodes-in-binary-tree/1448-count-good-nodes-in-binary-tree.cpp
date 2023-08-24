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
    void solve(TreeNode* root, int &count, int max_val){
        if(!root) return;
        if(max_val<=root->val){
            count++;
            max_val=root->val;
        }
        solve(root->left,count,max_val);
        solve(root->right,count,max_val);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        if(!root) return count;
        solve(root,count,root->val);
        return count;
    }
};