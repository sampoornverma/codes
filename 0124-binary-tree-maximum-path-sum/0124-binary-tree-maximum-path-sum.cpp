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
    int f(TreeNode* root,int &maxi){
        if(root==nullptr){

            return 0;
        }
        int rh=0;
        if(root->right)rh=max(0,f(root->right,maxi));
        int lh=0;
        if(root->left)lh=max(0,f(root->left,maxi));
        maxi=max(maxi,lh+rh+root->val);
        return max(lh,rh)+root->val;

    }
    int maxPathSum(TreeNode* root) {
        int maxi=-1000000;
         f(root,maxi);
        return maxi;
    }
};