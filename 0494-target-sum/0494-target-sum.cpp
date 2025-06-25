class Solution {
public:
    const int MOD = 1e9 + 7;

    int findTargetSumWays(vector<int>& arr, int d) {
        int range = accumulate(arr.begin(), arr.end(), 0);

        // Check if valid partition is possible
        if ((range + d) % 2 != 0 || range < abs(d)) return 0;

        int sum = (range + d) / 2;
        int n = arr.size();

        // Initialize DP table
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // Base case: One way to make sum 0 from any number of elements (by picking nothing)
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        // Build DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};