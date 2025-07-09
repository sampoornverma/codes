class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (!st.empty() || node != nullptr) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();  // ✅ Don't redeclare here
                st.pop();
                arr.push_back(node->val);
                node = node->right;
            }
        }

        return arr;
    }
};