class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> q;
        vector<vector<int>> arr;
        q.push(root);
        bool flag = true;

        while (!q.empty()) {
            int s = q.size();
            vector<int> x(s);
            for (int i = 0; i < s; i++) {
                TreeNode* c = q.front();
                q.pop();
                int index = flag ? i : (s - 1 - i);
                x[index] = c->val;

                if (c->left) q.push(c->left);
                if (c->right) q.push(c->right);
            }
            flag = !flag;
            arr.push_back(x);
        }   
        return arr;
    }
};