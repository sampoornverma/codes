class Solution {
public:

    int f(int i, int buy, int no, vector<int>& prices, vector<vector<vector<int>>>& dp){

        if(i == prices.size() || no == 2)
            return 0;

        if(dp[i][buy][no] != -1)
            return dp[i][buy][no];

        int profit = 0;

        if(buy == 0) // can buy
        {
            profit = max(
                -prices[i] + f(i+1,1,no,prices,dp),
                f(i+1,0,no,prices,dp)
            );
        }
        else // must sell
        {
            profit = max(
                prices[i] + f(i+1,0,no+1,prices,dp),
                f(i+1,1,no,prices,dp)
            );
        }

        return dp[i][buy][no] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(2, vector<int>(3,-1)));

        return f(0,0,0,prices,dp);
    }
};