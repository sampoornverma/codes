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
 void f(BinaryTreeNode<int>* node, vector<string>& a) {
    if (node == nullptr) {
        a.push_back("null");
        return;
    }

    a.push_back(to_string(node->val));
    f(node->left, a);
    f(node->right, a);
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> a, b;
    f(p, a);
    f(q, b);
    return a == b;
    }
};