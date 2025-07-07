class Solution {
public:
    int depth(TreeNode* node, int &diameter) {
        if (node == nullptr) return 0;

        int leftDepth = depth(node->left, diameter);
        int rightDepth = depth(node->right, diameter);

        // Update the diameter if the path through this node is longer
        diameter = max(diameter, leftDepth + rightDepth);

        // Return height of the current node
        return 1 + max(leftDepth, rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }


    
};