class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp1;
        vector<int>ans(A.size());
        int count = 0;
        for(int i = 0; i<A.size(); i++){
             mp1[A[i]]++;
             if(mp1[A[i]] == 2) count++;
             mp1[B[i]]++;
             if(mp1[B[i]] == 2) count++;

             ans[i] = count;
        }
        return ans;
    }
};