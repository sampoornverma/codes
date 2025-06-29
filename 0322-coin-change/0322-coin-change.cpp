class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        const int INF = 1e9; 
        vector< vector<int>> dp(n, vector<int>(amount +1,INF));
        for (int i = 0; i < n; i++) dp[i][0] = 0;
        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int notPick = dp[i - 1][j];
                int pick = INF;
                if (coins[i] <= j)
                    pick = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(pick, notPick);
            }
        }
        return (dp[n - 1][amount] == INF) ? -1 : dp[n - 1][amount];

        
    }
};