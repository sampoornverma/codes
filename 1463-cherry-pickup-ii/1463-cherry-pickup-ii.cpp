class Solution {
public:
    int f(vector<vector<int>>& o, vector<vector<vector<int>>>& dp, int n, int m, int i, int j1, int j2) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;

        if (i == n - 1) {
            if (j1 == j2) return o[i][j1];
            else return o[i][j1] + o[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int max1 = -1e9;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int nextJ1 = j1 + dj1;
                int nextJ2 = j2 + dj2;
                int value = (j1 == j2) ? o[i][j1] : o[i][j1] + o[i][j2];
                value += f(o, dp, n, m, i + 1, nextJ1, nextJ2);
                max1 = max(max1, value);
            }
        }

        return dp[i][j1][j2] = max1;
    }

    int cherryPickup(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(o, dp, n, m, 0, 0, m - 1);
    }
};