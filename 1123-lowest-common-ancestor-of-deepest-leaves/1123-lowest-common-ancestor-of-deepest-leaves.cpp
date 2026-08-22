class Solution {
public:
    int f(TreeNode* root) {
        if (root == nullptr) return -1;

        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }

        return 1 + max(f(root->left), f(root->right));
    }

    TreeNode* g(TreeNode* root, int currDepth, int maxDepth) {
        if (root == nullptr) return nullptr;

        // If this is a deepest leaf
        if (root->left == nullptr && root->right == nullptr) {
            if (currDepth == maxDepth) return root;
            return nullptr;
        }

        TreeNode* left = g(root->left, currDepth + 1, maxDepth);
        TreeNode* right = g(root->right, currDepth + 1, maxDepth);

     if (left && right) return root;

        if (left) return left;

        return right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = f(root);

        return g(root, 0, depth);
    }
};