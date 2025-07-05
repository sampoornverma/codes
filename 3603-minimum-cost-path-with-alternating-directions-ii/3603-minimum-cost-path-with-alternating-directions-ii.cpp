class Solution {
public:
    long long f(int m, int n, vector<vector<int>>& waitCost, int time, vector<vector<long long>>& dp, int i, int j) {
        if (i == m || j == n) return 1e16;  
        if (i == m - 1 && j == n - 1) return 1; 

        if (dp[i][j] != -1) return dp[i][j];

        if (time % 2 != 0) {
            long long downCost = (i + 2) * (j + 1) + f(m, n, waitCost, time + 1, dp, i + 1, j);
            long long rightCost = (i + 1) * (j + 2) + f(m, n, waitCost, time + 1, dp, i, j + 1);
            return dp[i][j] = min(downCost, rightCost);
        } else {
            return dp[i][j] = waitCost[i][j] + f(m, n, waitCost, time + 1, dp, i, j);
        }
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        return f(m, n, waitCost, 1, dp, 0, 0);  
    }
};