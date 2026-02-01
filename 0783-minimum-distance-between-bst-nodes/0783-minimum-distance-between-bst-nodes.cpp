class Solution {
public:
    int mini = INT_MAX;
    int prev = -1;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        if (prev != -1) {
            mini = min(mini, root->val - prev);
        }
        prev = root->val;

        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return mini;
    }
};