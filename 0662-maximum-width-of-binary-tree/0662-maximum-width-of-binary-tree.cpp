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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>> q;
        int maxi=1;
        q.push({root,1});
        while(!q.empty()){
            int first=q.front().second;
            int end=q.back().second;
            maxi=max(maxi,end-first+1);
            int sz=q.size();
            while(sz--){
                auto [node, pos] = q.front();
                q.pop();
                long long normalized = pos - first;
                if(node->left)q.push({node->left,normalized*2});
                if(node->right)q.push({node->right,normalized*2+1});

            }
            }
            return maxi;
        
    }
};