class Solution {
public:
    void f(vector<int>& in, TreeNode* root) {
        if (root == nullptr) return;

        f(in, root->left);
        in.push_back(root->val);
        f(in, root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int> in;
        f(in, root);

        vector<vector<int>> ans;

        for (int x : q) {
            vector<int> temp;

            // First element >= x
            auto it = lower_bound(in.begin(), in.end(), x);

            // Floor: largest value <= x
            int first;
            if (it != in.end() && *it == x) {
                first = x;
            } else if (it == in.begin()) {
                first = -1;
            } else {
                first = *prev(it);
            }

            // Ceil: smallest value >= x
            int second;
            if (it == in.end()) {
                second = -1;
            } else {
                second = *it;
            }

            temp.push_back(first);
            temp.push_back(second);
            ans.push_back(temp);
        }

        return ans;
    }
};