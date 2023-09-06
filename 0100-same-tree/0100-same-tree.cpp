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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<TreeNode*> qp;
        queue<TreeNode*> qq;
        qp.push(p);
        qq.push(q);
        while(!qp.empty() && !qq.empty()){
            TreeNode* np = qp.front(); qp.pop();
            TreeNode* nq = qq.front(); qq.pop();
            if(np->val!=nq->val) return false;
            if(np->left && nq->left){
                qp.push(np->left);
                qq.push(nq->left);
            }
            else if(np->left || nq->left)  return false;
            
            if(np->right && nq->right){
                qp.push(np->right);
                qq.push(nq->right);
            }
            else if(np->right || nq->right)  return false;
        }
        return true;
    }
};