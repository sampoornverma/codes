class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        int n = piles.size();

        vector<vector<int>> dp(n+1, vector<int>(k+1,0));

        for(int i = 1; i <= n; i++){

            for(int j = 0; j <= k; j++){

                dp[i][j] = dp[i-1][j];

                int sum = 0;

                for(int x = 0; x < piles[i-1].size() && x < j; x++){
                    sum += piles[i-1][x];

                    dp[i][j] = max(dp[i][j],
                                   sum + dp[i-1][j-x-1]);
                }
            }
        }

        return dp[n][k];
    }
};