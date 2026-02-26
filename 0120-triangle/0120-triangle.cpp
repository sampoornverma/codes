class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        int m = t[n-1].size();

        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        dp[0][0] = t[0][0];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < t[i].size(); j++){
                if(i == 0 && j == 0) continue;

                int left = 1e9;
                if(j-1 >= 0)
                    left = dp[i-1][j-1];

                int top = 1e9;
                if(j < t[i-1].size())
                    top = dp[i-1][j];

                dp[i][j] = t[i][j] + min(top, left);
            }
        }

        int maxi = 1e9;
        for(int i = 0; i < m; i++){
            maxi = min(maxi, dp[n-1][i]);
        }
        return maxi;
    }
};