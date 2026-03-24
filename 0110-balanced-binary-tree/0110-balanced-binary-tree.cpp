class Solution {
public:

    int b(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = b(root->left);
        if(lh == -1) return -1;

        int rh = b(root->right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return b(root) != -1;
    }
};