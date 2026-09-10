class Solution {
public:

    void dfs(TreeNode* node, int &countsub, int &sum, int &count) {

        if (node == nullptr)
            return;

        int leftSum = 0;
        int leftCount = 0;

        int rightSum = 0;
        int rightCount = 0;

        dfs(node->left, countsub, leftSum, leftCount);
        dfs(node->right, countsub, rightSum, rightCount);

        sum = leftSum + rightSum + node->val;
        count = leftCount + rightCount + 1;

        if (sum / count == node->val) {
            countsub++;
        }
    }

    int averageOfSubtree(TreeNode* root) {

        int countsub = 0;

        int sum = 0;
        int count = 0;

        dfs(root, countsub, sum, count);

        return countsub;
    }
};