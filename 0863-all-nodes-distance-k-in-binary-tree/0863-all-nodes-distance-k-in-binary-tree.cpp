/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,TreeNode*> parent_list;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent_list[node->left->val]=node;
                q.push(node->left);
            }
            if(node->right){
                parent_list[node->right->val]=node;
                q.push(node->right);
            }
        }
        
        unordered_map<int,int> visited;
        q.push(target);
        while(k-- && !q.empty()){
            int l=q.size();
            for(int i=0; i<l; i++){
                TreeNode* node=q.front();
                q.pop();
                visited[node->val]=1;
                
                if(node->left && !visited[node->left->val]){
                    q.push(node->left);
                }
                if(node->right && !visited[node->right->val]){
                    q.push(node->right);
                }
                if(parent_list[node->val] && !visited[parent_list[node->val]->val]){
                    q.push(parent_list[node->val]);
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};