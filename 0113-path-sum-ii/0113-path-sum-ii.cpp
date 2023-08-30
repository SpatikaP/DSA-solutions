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
    void solve(TreeNode* root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &res){
        if(!root) return;
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right) {
            if(sum==targetSum) res.push_back(temp);
        }
        solve(root->left,targetSum,sum,temp,res);
        solve(root->right,targetSum,sum,temp,res);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum=0;
        solve(root,targetSum,sum,temp,res);
        return res;
    }
};