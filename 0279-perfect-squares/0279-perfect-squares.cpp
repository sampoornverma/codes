class Solution {
public:

    int f(int n,vector<int> &dp){

        if(n == 0)
            return 0;
        if(dp[n]!= -1) return dp[n];
        int ans = 1e9;

        for(int i = 1; i*i <= n; i++){

            ans = min(ans, 1 + f(n - i*i,dp));
        }

        return dp[n]= ans;
    }

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};