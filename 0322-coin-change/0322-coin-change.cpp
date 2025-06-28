class Solution {
public:
    int f(vector<int>& coins, int amount, vector<vector<int>>& dp, int i) {
        if (amount == 0) return 0;               // Base: exact amount formed
        if (amount < 0 || i >= coins.size()) return 1e9; // Base: not possible
        if (dp[i][amount] != -1) return dp[i][amount];

        // Pick the coin (stay on the same coin as we can reuse it)
        int pick = 1 + f(coins, amount - coins[i], dp, i);

        // Not pick the coin (move to next coin)
        int notPick = f(coins, amount, dp, i + 1);

        return dp[i][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(coins, amount, dp, 0);
        return (ans >= 1e9 ? -1 : ans);  // If impossible, return -1
    }
};