class Solution {
public:
    int minScore(int n, vector<vector<int>>& r) {
        int mini=1e9;
    for(int i=0;i<r.size();i++){
        mini=min(mini,r[i][2]);
    } 
    return mini;  
    }
};