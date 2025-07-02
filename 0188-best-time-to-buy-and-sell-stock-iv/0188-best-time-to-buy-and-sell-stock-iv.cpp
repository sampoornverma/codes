class Solution {
public:
    int f(vector<int>& prices, int i, int buy, int cap, vector<vector<vector<int>>>& dp) {
        if (cap == 0 || i == prices.size()) return 0;

        if (dp[i][buy][cap] != -1) return dp[i][buy][cap];

        if (buy) {
            // We can buy or skip
            int take = -prices[i] + f(prices, i + 1, 0, cap, dp);
            int skip = f(prices, i + 1, 1, cap, dp);
            return dp[i][buy][cap] = max(take, skip);
        } else {
            // We can sell or skip
            int sell = prices[i] + f(prices, i + 1, 1, cap - 1, dp);
            int skip = f(prices, i + 1, 0, cap, dp);
            return dp[i][buy][cap] = max(sell, skip);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(prices, 0, 1, k, dp);  // start from day 0, buy state = 1, cap = k
    }
};