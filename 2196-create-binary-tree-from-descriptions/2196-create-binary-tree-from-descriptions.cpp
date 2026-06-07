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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,TreeNode* > mp;
        unordered_set<int> st;

        for(int i=0;i<d.size();i++){
            int x=d[i][0];
            int y=d[i][1];
            int z=d[i][2];

            if(mp.find(x) == mp.end()){
                mp[x]= new TreeNode(x);
            }
            if(mp.find(y) == mp.end()){
                mp[y]= new TreeNode(y);
            }
            if(z==1){
                mp[x]->left=mp[y];
            }else mp[x]->right=mp[y];
            st.insert(y);
        }
        for(int i=0;i<d.size();i++){
            int x=d[i][0];
            if(st.find(x)==st.end())return mp[x];
        }
        return nullptr;
    }
};