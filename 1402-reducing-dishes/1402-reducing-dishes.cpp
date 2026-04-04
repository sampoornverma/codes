class Solution {
public:
    int f(int i,int c,vector<int>& s, vector<vector<int>>& dp){
        if(i>=s.size())return 0;
        if(dp[i][c]!=-1)return dp[i][c];
        int take=c*s[i]+f(i+1,c+1,s,dp);
        int nt=f(i+1,c,s,dp);
        return dp[i][c]=max(take,nt);
    }
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
       sort(s.begin(),s.end());
       vector<vector<int>> dp(501, vector<int>(510, -1));
       return f(0,1,s,dp); 
    }
};