class Solution {
public:
    int n,m;

    int f(int i,int j,int k,vector<vector<int>>& coins,
          vector<vector<vector<int>>>& dp){

        if(i>=n || j>=m)
            return INT_MIN;

        if(i==n-1 && j==m-1){
            if(coins[i][j] < 0 && k>0)
                return 0;
            return coins[i][j];
        }

        if(dp[i][j][k] != INT_MIN)
            return dp[i][j][k];

        int right = f(i,j+1,k,coins,dp);
        int down  = f(i+1,j,k,coins,dp);

        int best = max(right,down);

        int ans = INT_MIN;

        if(best != INT_MIN)
            ans = coins[i][j] + best;

        if(coins[i][j] < 0 && k>0){
            int r = f(i,j+1,k-1,coins,dp);
            int d = f(i+1,j,k-1,coins,dp);
            ans = max(ans, max(r,d));
        }

        return dp[i][j][k] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {

        n = coins.size();
        m = coins[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        return f(0,0,2,coins,dp);
    }
};