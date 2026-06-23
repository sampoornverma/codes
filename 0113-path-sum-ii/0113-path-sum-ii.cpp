class Solution {
public:
    void f(vector<vector<int>>& ans,
           vector<int>& arr,
           TreeNode* root,
           int target) {

        if (root == nullptr)
            return;

        if (root->left == nullptr &&
            root->right == nullptr) {

            if (target == 0)
                ans.push_back(arr);

            return;
        }

        if (root->left) {
            arr.push_back(root->left->val);
            f(ans, arr, root->left,
              target - root->left->val);
            arr.pop_back();
        }

        if (root->right) {
            arr.push_back(root->right->val);
            f(ans, arr, root->right,
              target - root->right->val);
            arr.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        vector<int> arr;
        arr.push_back(root->val);

        f(ans, arr, root,
          targetSum - root->val);

        return ans;
    }
};