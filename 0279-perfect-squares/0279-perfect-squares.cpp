class Solution {
public:
    int f(int n,vector<int> &dp){
        if(n==0)return 0;
        if(dp[n]!=0)return dp[n];
        int maxi=1e9;
        for(int i=1;i*i<=n;i++){
            maxi=min(maxi,1+f(n-i*i,dp));
        }
        return dp[n]=maxi;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        return f(n,dp);
    }
};