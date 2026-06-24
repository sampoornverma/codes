class Solution {
public:
    bool isleaf(TreeNode* x){
        return x->left == nullptr && x->right == nullptr;
    }

    TreeNode* delete1(TreeNode* root, TreeNode* o){

        if(isleaf(root)){
            delete root;
            return nullptr;
        }

        else{
            if(root->left){

                TreeNode* temp = root->left;

                while(temp->right){
                    temp = temp->right;
                }

                TreeNode* j = temp;

                root->val = j->val;

                root->left = deleteNode(root->left, j->val);

                return root;
            }
            else{

                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == nullptr) return nullptr;

        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            return delete1(root, root);
        }

        return root;
    }
};