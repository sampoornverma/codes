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
    void f(TreeNode* node,int level,vector<int>& res){
        if(node==nullptr)return ;
        if(res.size()==level)res.push_back(node->val);
        f(node->left,level+1,res);
        f(node->right,level+1,res);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> res;
        f(root,0,res);
        return res[res.size()-1];
    }
};