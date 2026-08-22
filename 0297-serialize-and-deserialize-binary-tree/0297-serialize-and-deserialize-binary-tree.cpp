/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr)s.append("#,");
            else s.append(to_string(curr->val)+",");
            if(curr!=nullptr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data=="#,"|| data.empty()){
            return nullptr;
        }
        stringstream ss(data);
        string val;
        getline(ss,val,',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            getline(ss, val, ',');
        if(val!="#"){
             curr->left = new TreeNode(stoi(val));

                q.push(curr->left);
        }
        getline(ss, val, ',');
            if (val != "#") {

                curr->right = new TreeNode(stoi(val));

                q.push(curr->right);

            }
        }

        return root;
    }
};
