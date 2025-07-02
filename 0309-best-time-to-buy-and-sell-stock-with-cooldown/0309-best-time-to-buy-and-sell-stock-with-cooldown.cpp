class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        if (buy) {
            // Option to buy or skip
            int buyOp = -prices[i] + solve(i + 1, 0, prices, dp);
            int skip = solve(i + 1, 1, prices, dp);
            return dp[i][buy] = max(buyOp, skip);
        } else {
            // Option to sell or skip
            int sellOp = prices[i] + solve(i + 2, 1, prices, dp); // cooldown 1 day
            int skip = solve(i + 1, 0, prices, dp);
            return dp[i][buy] = max(sellOp, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};