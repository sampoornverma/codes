class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        long long maxi = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});

        while (!q.empty()) {
            int x = q.size();

            // the first and last position at this level
            long long first = q.front().second;
            long long last = q.back().second;

            // update max width with this level's width
            maxi = max(maxi, last - first + 1);

            // process children
            while (x--) {
                auto [node, pos] = q.front();
                q.pop();

                if (node->left)
                    q.push({node->left, pos * 2});
                if (node->right)
                    q.push({node->right, pos * 2 + 1});
            }
        }

        return (int)maxi;
    }
};