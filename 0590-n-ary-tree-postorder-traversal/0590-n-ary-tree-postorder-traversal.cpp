/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
void f(vector<int> &ans,Node* root){
if(root==nullptr)return;
    for(Node* a:root->children){
        f(ans,a);
    }
    ans.push_back(root->val);
}
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        f(ans,root);
        return ans;
    }
};