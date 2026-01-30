class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> qu;
        qu.push(root);

        while (!qu.empty()) {
            int levelSize = qu.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = qu.front();
                qu.pop();

                level.push_back(node->val);

                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};