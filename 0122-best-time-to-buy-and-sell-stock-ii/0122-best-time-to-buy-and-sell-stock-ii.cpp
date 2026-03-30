class Solution {
public:

    int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){

        if(i == prices.size())
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if(buy == 0) // can buy
        {
            profit = max(
                -prices[i] + f(i+1,1,prices,dp), // buy
                f(i+1,0,prices,dp)               // skip
            );
        }
        else // must sell
        {
            profit = max(
                prices[i] + f(i+1,0,prices,dp),  // sell
                f(i+1,1,prices,dp)               // hold
            );
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return f(0,0,prices,dp);
    }
};