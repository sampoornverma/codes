class Solution {
public:

    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {

        // No cut between i and j
        if (i + 1 == j)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int cost = cuts[j] - cuts[i];
        int mini = 1e9;

        for (int k = i + 1; k < j; k++) {

            int ans = f(i, k, cuts, dp)
                    + f(k, j, cuts, dp);

            mini = min(mini, ans);
        }

        return dp[i][j] = mini + cost;
    }

    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return f(0, m - 1, cuts, dp);
    }
};