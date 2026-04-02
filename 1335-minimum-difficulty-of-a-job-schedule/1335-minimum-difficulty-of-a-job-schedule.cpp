class Solution {
public:

    int f(vector<vector<int>> &dp, vector<int>& j, int d, int i){

        int n = j.size();

        if(d == 1){
            int maxi = 0;
            for(int x = i; x < n; x++){
                maxi = max(maxi, j[x]);
            }
            return maxi;
        }

        if(dp[i][d] != -1)
            return dp[i][d];

        int maxi = 0;
        int ans = INT_MAX;

        for(int k = i; k <= n - d; k++){

            maxi = max(maxi, j[k]);

            int next = f(dp, j, d-1, k+1);

            ans = min(ans, maxi + next);
        }

        return dp[i][d] = ans;
    }

    int minDifficulty(vector<int>& j, int d) {

        int n = j.size();

        if(n < d)
            return -1;

        vector<vector<int>> dp(n, vector<int>(d+1, -1));

        return f(dp, j, d, 0);
    }
};