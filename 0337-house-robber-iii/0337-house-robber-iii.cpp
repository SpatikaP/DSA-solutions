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
    
    int rob(TreeNode* root) {
        vector<int> res = travel(root);
        return max(res[0],res[1]);
    }
    
     vector<int> travel(TreeNode* root){
        
        vector<int> option(2);
        
        if(!root) return {0, 0};
        vector<int> left_choice = travel(root->left);
        vector<int> right_choice = travel(root->right);
        
        
        option[0]=root->val+left_choice[1]+right_choice[1];
        option[1]=max(left_choice[0],left_choice[1])+max(right_choice[0],right_choice[1]);
        
        return option;
    }
    
};







