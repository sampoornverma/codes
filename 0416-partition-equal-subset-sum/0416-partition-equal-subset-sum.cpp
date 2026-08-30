class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Odd total sum cannot be divided equally
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Target 0 is always possible
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Using only nums[0]
        if(nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        // DP
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {

                bool notTaken = dp[i - 1][j];
                bool taken = false;
                if(nums[i] <= j) {
                    taken = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = notTaken || taken;
            }
        }

        return dp[n - 1][target];
    }
};