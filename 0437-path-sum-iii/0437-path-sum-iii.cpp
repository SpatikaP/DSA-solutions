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
    void findPath(TreeNode* root, long sum, int targetSum){
        
        if(!root) return;
        
        sum+=root->val;
        
        if(targetSum==sum) total++;
        
        findPath(root->left,sum,targetSum);
        findPath(root->right,sum,targetSum);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root) return 0;
        
        findPath(root,0,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return total;
    }
};