class Solution {
public:
    int f(vector<int>& prices,vector<vector<int>>& dp,int i,int buy,int n){
        if(i==n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy == 1){
            return dp[i][buy]=max(-prices[i]+f(prices,dp,i+1,0,n),f(prices,dp,i+1,1,n));
        }
        else{
            return dp[i][buy]=max(prices[i]+f(prices,dp,i+1,1,n),f(prices,dp,i+1,0,n));
        }

    }
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,dp,0,1,n);
    }
};