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
    int f(TreeNode* root){
        if(root==nullptr)return 0;
        return 1+ max(f(root->left),f(root->right));
    }
    bool isBalanced(TreeNode* root) {
    if(root==nullptr)return true;
    int a=0,b=0;
    if(root->left != nullptr) a= f(root->left);
    
    if(root->right != nullptr) b= f(root->right);
    
    int c=abs(a-b);
    if(c>1)return false;
     return true;

    }
};