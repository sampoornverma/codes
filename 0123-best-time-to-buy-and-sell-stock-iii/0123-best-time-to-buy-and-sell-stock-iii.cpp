class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int k=2;

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(k + 1, 0))
        );

        // dp[n][*][*] = 0 already
        // dp[*][*][0] = 0 already

        for (int i = n - 1; i >= 0; i--) {


                for (int cap = 1; cap <= k; cap++) {

                  

                        dp[i][0][cap] = max(
                            dp[i + 1][0][cap],                  // Skip
                            -prices[i] + dp[i + 1][1][cap]      // Buy
                        );

                    

                        dp[i][1][cap] = max(
                            dp[i + 1][1][cap],                  // Hold
                            prices[i] + dp[i + 1][0][cap - 1]   // Sell
                        );
                    
                
            }
        }

        return dp[0][0][k];
    }
};