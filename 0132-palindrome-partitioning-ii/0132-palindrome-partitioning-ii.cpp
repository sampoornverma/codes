class Solution {
public:

    int f(int i, string &s, int n, vector<int>& dp,
          vector<vector<bool>>& pal) {

        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for (int j = i; j < n; j++) {

            if (pal[i][j]) {

                int cuts = 1 + f(j + 1, s, n, dp, pal);

                ans = min(ans, cuts);
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {

        int n = s.size();

        // pal[i][j] = whether s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n, -1);

        return f(0, s, n, dp, pal) - 1;
    }
};