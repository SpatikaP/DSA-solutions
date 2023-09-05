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
    int max_sum=INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;
        int l=max(solve(root->left),0);
        int r=max(solve(root->right),0);
        int sum=l+r+root->val;
        max_sum=max(max_sum,sum);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return max_sum;
    }
};