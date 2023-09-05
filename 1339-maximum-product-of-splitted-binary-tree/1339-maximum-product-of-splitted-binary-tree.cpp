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
    long sum=0;
    long maxP=0;
    
    int totalSum(TreeNode* root){
        if(!root) return 0;
        int l = totalSum(root->left);
        int r = totalSum(root->right);
        return root->val+l+r;
    }
    
    int find(TreeNode* root){

        if(!root) return 0;
        
        int leftSum = find(root->left);
        int rightSum = find(root->right);
        
        long subTreeSum = root->val+leftSum+rightSum;
        
        long remainingSubtreeSum = sum-subTreeSum;
        
        maxP = max(maxP,subTreeSum*remainingSubtreeSum);
        
        return subTreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        maxP=0;
        sum = totalSum(root);
        find(root);
        return maxP%(1000000007);
    }
};