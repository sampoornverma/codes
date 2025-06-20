class Solution {
public:
    int f(vector<vector<int>>& o, vector<vector<int>>& dp, int i, int j) {
        int n = o.size();
        if (i == n - 1) return o[i][j]; // Base case: bottom row

        if (dp[i][j] != -1) return dp[i][j]; // Use memoized result

        int down = o[i][j] + f(o, dp, i + 1, j);
        int diagonal = o[i][j] + f(o, dp, i + 1, j + 1);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& o) {
        int n = o.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Memo table
        return f(o, dp, 0, 0);
    }
};