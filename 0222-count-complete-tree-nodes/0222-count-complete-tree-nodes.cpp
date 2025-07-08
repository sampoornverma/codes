class Solution {
public:
    int rh(TreeNode* root) {
        int count = 0;
        while (root) {
            root = root->right;
            count++;
        }
        return count;
    }

    int lh(TreeNode* root) {
        int count = 0;
        while (root) {
            root = root->left;
            count++;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh1 = lh(root);
        int rh1 = rh(root);

        if (lh1 == rh1)
            return (1 << lh1) - 1;  // 2^height - 1

        // Recursively count left and right
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};