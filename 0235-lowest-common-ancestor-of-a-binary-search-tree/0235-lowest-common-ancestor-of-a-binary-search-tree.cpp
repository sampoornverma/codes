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
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr)return root;
        if((p->val<=root->val && q->val>=root->val) || (p->val>=root->val && q->val<=root->val))return root;
        else if(p->val<root->val && q->val<root->val)return f(root->left,p,q);
        else return  f(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};