class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                              vector<int>& postorder, int postStart, int postEnd,
                              unordered_map<int, int>& inorderIndexMap) {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int inRoot = inorderIndexMap[rootVal];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                     postorder, postStart, postStart + numsLeft - 1,
                                     inorderIndexMap);

        root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                      postorder, postStart + numsLeft, postEnd - 1,
                                      inorderIndexMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, 0, inorder.size() - 1,
                               postorder, 0, postorder.size() - 1,
                               inorderIndexMap);
    }
};