class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {

        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        // base cell
        for(int k=0;k<3;k++){
            if(coins[0][0] < 0 && k>0)
                dp[0][0][k] = 0;
            else
                dp[0][0][k] = coins[0][0];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 && j==0) continue;

                for(int k=0;k<3;k++){

                    int bestPrev = INT_MIN;

                    if(i>0)
                        bestPrev = max(bestPrev, dp[i-1][j][k]);

                    if(j>0)
                        bestPrev = max(bestPrev, dp[i][j-1][k]);

                    int ans = INT_MIN;

                    if(bestPrev != INT_MIN)
                        ans = coins[i][j] + bestPrev;

                    if(coins[i][j] < 0 && k>0){

                        int bestNeutral = INT_MIN;

                        if(i>0)
                            bestNeutral = max(bestNeutral, dp[i-1][j][k-1]);

                        if(j>0)
                            bestNeutral = max(bestNeutral, dp[i][j-1][k-1]);

                        ans = max(ans, bestNeutral);
                    }

                    dp[i][j][k] = ans;
                }
            }
        }

        return dp[n-1][m-1][2];
    }
};