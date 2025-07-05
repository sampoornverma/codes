class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  // ✅ Fixed

        vector<int> dp(n, 1);      
        vector<int> count(n, 1);   

        int maxIndex = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {  // ✅ Fixed
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (nums[i] > nums[j] && dp[j] + 1 == dp[i]) {  // ✅ Fixed
                    count[i] += count[j];
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        int maxiii = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == dp[maxIndex]) {
                maxiii += count[i];
            }
        }

        return maxiii;
    }
};