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
    unordered_map<int,int> mp;
    void dfs(TreeNode* node){
        if(!node) return;
        dfs(node->left);
        ++mp[node->val];
        dfs(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxf=0;
        dfs(root);
        for(auto x:mp){
            maxf=max(maxf,x.second);
        }
        for(auto x:mp){
            if(x.second==maxf) ans.push_back(x.first);
        }
        return ans;
        
    }
};