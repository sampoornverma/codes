class Solution {
public:
    bool match(string &s, string &p, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) return true;          // Both strings exhausted
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if (j < 0) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = match(s, p, i - 1, j - 1, dp);
        } else if (p[j] == '*') {
            // Two choices: '*' matches current char OR it doesn't
            return dp[i][j] = match(s, p, i - 1, j, dp) || match(s, p, i, j - 1, dp);
        } else {
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return match(s, p, n - 1, m - 1, dp);
    }
};