#include <climits>

class Solution {
public:
    int f(TreeNode* node, int &maxi) {
        if (node == nullptr) return 0;

        int ls = f(node->left, maxi);
        int rs = f(node->right, maxi);

        // max path through current node (may include both left and right)
        int throughNode = ls + rs + node->val;

        // update global max with best option so far
        maxi = max(maxi, max(node->val, max(throughNode, node->val + max(ls, rs))));

        // return best one-sided path
        return node->val + max(0, max(ls, rs));
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        f(root, maxi);
        return maxi;
    }
};