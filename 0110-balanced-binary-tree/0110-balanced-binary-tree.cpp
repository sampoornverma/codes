class Solution {
public:
    // Calculates height of a subtree
    int f(TreeNode* node){
        if(node == nullptr) return 0;
        return 1 + max(f(node->right), f(node->left));
    }

    // Checks if a tree is height-balanced
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int a = f(root->right);
        int b = f(root->left);
        int c = abs(a - b);

        // Current node is balanced and both subtrees must also be balanced
        if(c <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        } else {
            return false;
        }
    }
};