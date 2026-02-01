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
    int sum=-1001;
    int p(TreeNode* root){
        if(root==nullptr) return 0;
        int lh=p(root->left);
        int rh=p(root->right);
        sum=max(sum,max(lh+rh+root->val,root->val));
        return max(lh,rh)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        p(root);
        return sum;
    }
};