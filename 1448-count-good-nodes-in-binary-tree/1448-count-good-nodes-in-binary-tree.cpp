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
    int f(TreeNode* root,int val){
        if(root == nullptr)return 0;
        if(val<=root->val){
           return 1+f(root->right,root->val)+f(root->left,root->val);
        }
        return f(root->right,val)+f(root->left,val);
        
    }
    int goodNodes(TreeNode* root) {
        return 1+f(root->right,root->val)+f(root->left,root->val);
    }
};