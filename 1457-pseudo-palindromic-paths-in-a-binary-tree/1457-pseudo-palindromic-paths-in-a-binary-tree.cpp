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
    void dfs(TreeNode* root, vector<int> v, int &cnt){
        if(root==NULL) return;
        v[root->val]++;
        dfs(root->left,v,cnt);
        dfs(root->right,v,cnt);
        
        if(root->left==NULL && root->right==NULL){
            int z=0;
            for(auto e:v){
                if(e%2 != 0) z++;
            }
            if(z==1 || z==0) cnt++;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int count=0;
        dfs(root,freq,count);
        return count;
    }
};