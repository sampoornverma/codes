class Solution {
public:

    TreeNode* f(vector<int>& preorder, int prestart, int preend,
                vector<int>& inorder, int instart, int inend,
                unordered_map<int, int>& mp) {  // pass by reference!
        
        if (prestart > preend || instart > inend)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mp[root->val];                    // Correct mapping
        int numsleft = inroot - instart;

        root->left = f(preorder, prestart + 1, prestart + numsleft,
                       inorder, instart, inroot - 1, mp);

        root->right = f(preorder, prestart + numsleft + 1, preend,
                        inorder, inroot + 1, inend, mp); // Corrected this line

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        // Fix this loop: we want index from inorder (not preorder)
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return f(preorder, 0, preorder.size() - 1,
                 inorder, 0, inorder.size() - 1, mp);
    }
};