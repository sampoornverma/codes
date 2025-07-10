/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Node with only one child or no child
            if (!root->left) return root->right;
            else if (!root->right) return root->left;

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = findMin(root->right);

            // Copy the inorder successor's value to this node
            root->val = temp->val;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
        
    }
};