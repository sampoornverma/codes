class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> ms;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}}); // node, (column, row)

        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            TreeNode* node = x.first;
            int col = x.second.first;
            int row = x.second.second;

            ms[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        vector<vector<int>> ans;

        for (auto &colPair : ms) {
            vector<int> colVals;
            for (auto &rowPair : colPair.second) {
                colVals.insert(
                    colVals.end(),
                    rowPair.second.begin(),
                    rowPair.second.end()
                );
            }
            ans.push_back(colVals);
        }

        return ans;
    }
};