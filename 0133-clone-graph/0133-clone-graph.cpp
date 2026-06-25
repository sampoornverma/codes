/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<int,Node*>check;
        unordered_map<Node*,bool>m;
        queue<Node*>q;
        q.push(node);
        bool rootNode=true;
        while(!q.empty()){
            Node* top=q.front();
            q.pop();
            if(!m[top]){
                Node* newTop=new Node(top->val);
                check[newTop->val]=newTop;
                for(int i=0;i<top->neighbors.size();i++){
                    if(check.count(top->neighbors[i]->val)==0) q.push(top->neighbors[i]);
                    else{
                        newTop->neighbors.push_back(check[top->neighbors[i]->val]);
                        check[top->neighbors[i]->val]->neighbors.push_back(newTop);
                    }
                }
            }
            m[top]=true;
        }
        return check[1];
    }
};