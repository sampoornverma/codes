class Solution {
public:
    int maxi = 0;

    int f(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = f(root->left);
        int rh = f(root->right);

        maxi = max(maxi, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return maxi;
    }
};