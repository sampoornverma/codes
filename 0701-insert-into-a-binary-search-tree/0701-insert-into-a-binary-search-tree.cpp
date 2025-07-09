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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* a= new TreeNode(val);
        if(root==nullptr) return a;
        TreeNode* c= root;
        while(root !=nullptr){
            if(val>root->val){
                if(root->right==nullptr){
                    root->right=a;
                    root=a->right;
                }else{
                    root=root->right;
                }
            }
            else{
                if(root->left==nullptr){
                    root->left=a;
                    root=a->left;
                }else{
                    root=root->left;
                }
            }
        }
        return c;
    }
};