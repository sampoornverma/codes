/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *>q;
        q.push(root);
        if(!root) return NULL;
        while(!q.empty()){
            int n=q.size();
            // Node * temp=NULL;
            while(n--){
                Node * curr=q.front();
                q.pop();
                if(n==0){
                    curr->next=NULL;
                }
                else{
                    curr->next=q.front();
                }
                // left exits 
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};