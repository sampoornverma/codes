#include <climits>

class Solution {
public:
    int f(TreeNode* node, int &maxi) {
        if (node == nullptr) return 0;

        int ls = max(f(node->left,maxi),0);
        int rs = max(f(node->right,maxi),0);

        // max path through current node (may include both left and right)
        int throughNode = ls + rs + node->val;

        // update global max with best option so far
        maxi = max(maxi, throughNode);

        // return best one-sided path
        return node->val + max(0, max(ls, rs));
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        f(root, maxi);
        return maxi;
    }
};