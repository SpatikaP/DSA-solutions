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
    unordered_map<int,vector<TreeNode*>> t;
    vector<TreeNode*> solve(int n){
        if(n%2==0) return {};
        if(n==1){
            TreeNode* root=new TreeNode(0);
            return {root};
        }
        if(t.find(n)!=t.end()) return t[n];
        vector<TreeNode*> result;
        for(int i=1; i<n; i+=2){
            vector<TreeNode*> L = solve(i);
            vector<TreeNode*> R = solve(n-i-1);
            
            for(auto &l:L){
                for(auto &r:R){
                    TreeNode* root= new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    result.push_back(root);
                }
            }
        }
        return t[n]=result;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};