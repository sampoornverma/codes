class Solution {
public:

    int f(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp){

        if(i == piles.size() || k == 0)
            return 0;

        if(dp[i][k] != -1)
            return dp[i][k];

        int ans = f(i+1, k, piles, dp); // skip this pile

        int sum = 0;

        for(int j = 0; j < piles[i].size() && j < k; j++){
            sum += piles[i][j];
            ans = max(ans, sum + f(i+1, k-j-1, piles, dp));
        }

        return dp[i][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        return f(0, k, piles, dp);
    }
};