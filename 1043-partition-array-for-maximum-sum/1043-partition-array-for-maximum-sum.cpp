class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<int>& dp) {

        int n = arr.size();

        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int maxi = 0;
        int ans = 0;
        for (int j = i; j < min(i + k, n); j++) {

            maxi = max(maxi, arr[j]);

            int len = j - i + 1;

            int cost = maxi * len + solve(j + 1, arr, k, dp);

            ans = max(ans, cost);
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();

        vector<int> dp(n, -1);

        return solve(0, arr, k, dp);
    }
};