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
    TreeNode* x=root;
    TreeNode* a= new TreeNode(val);
    while(root != nullptr){
        if(root->val > val){
            if(root->left==nullptr){
                root->left=a;
                return x;
            }
            root=root->left;
        }else{
          if(root->right==nullptr){
                root->right=a;
                return x;
            }
            root=root->right;  
        }  
        } 
    return x;
    }
};