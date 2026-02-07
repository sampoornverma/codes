class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        // flatten left and right subtrees first
        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // move left subtree to the right
        root->left = nullptr;
        root->right = left;

        // go to the end of the new right subtree
        TreeNode* curr = root;
        while (curr->right != nullptr) {
            curr = curr->right;
        }

        // attach original right subtree
        curr->right = right;
    }
};