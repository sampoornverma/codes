class Solution {
public:
    int maxSum = 0;

    class NodeValue {
    public:
        int minNode;
        int maxNode;
        int sum;

        NodeValue(int minNode, int maxNode, int sum) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->sum = sum;
        }
    };

    NodeValue dfs(TreeNode* root) {
        // Base case
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Postorder traversal
        NodeValue left = dfs(root->left);
        NodeValue right = dfs(root->right);

        // Check if valid BST
        if (left.maxNode < root->val && root->val < right.minNode) {
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        // Not a BST → return invalid range
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};