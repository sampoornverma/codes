class Solution {
public:
    int f(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if (dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int res = f(coins, amount - coins[i], dp);
            if (res != INT_MAX) {
                mini = min(mini, 1 + res);
            }
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int result = f(coins, amount, dp);
        return (result == INT_MAX) ? -1 : result;
    }
};