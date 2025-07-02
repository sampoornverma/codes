class Solution {
public:
    int f(vector<int>& prices, vector<vector<vector<int>>>& dp, int i, int buy, int count) {
        int n = prices.size();
        if (count == 4 || i == n) return 0;

        if (dp[i][buy][count] != -1) return dp[i][buy][count];

        if (buy == 1) {
            // Either buy or skip
            int pick = -prices[i] + f(prices, dp, i + 1, 0, count + 1);
            int notPick = f(prices, dp, i + 1, 1, count);
            return dp[i][buy][count] = max(pick, notPick);
        } else {
            // Either sell or skip
            int pick = prices[i] + f(prices, dp, i + 1, 1, count + 1);
            int notPick = f(prices, dp, i + 1, 0, count);
            return dp[i][buy][count] = max(pick, notPick);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(5, -1)));
        return f(prices, dp, 0, 1, 0); 
    }
};