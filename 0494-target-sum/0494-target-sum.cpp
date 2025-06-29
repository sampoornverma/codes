class Solution {
public:
    const int MOD = 1e9 + 7;

    int findTargetSumWays(vector<int>& arr, int d) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        // Check for invalid cases
        if ((totalSum + d) % 2 != 0 || (totalSum + d) < 0) 
            return 0;

        int target = (totalSum + d) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base case
        if (arr[0] == 0) {
            dp[0][0] = 2;  // pick and not pick (0 both ways)
        } else {
            dp[0][0] = 1;  // not pick
            if (arr[0] <= target)
                dp[0][arr[0]] = 1;  // pick
        }

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                int notTake = dp[i - 1][sum];
                int take = 0;
                if (arr[i] <= sum)
                    take = dp[i - 1][sum - arr[i]];
                dp[i][sum] = (take + notTake) % MOD;
            }
        }

        return dp[n - 1][target];
    }
};