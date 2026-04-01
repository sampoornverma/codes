class Solution {
public:
    int f(int i, vector<int>& nums, int p, vector<vector<int>>& dp){
        int n = nums.size();
        
        if(i == n) return 0;

        if(dp[i][p+1] != -1) 
            return dp[i][p+1];

        int notTake = f(i+1, nums, p, dp);

        int take = 0;
        if(p == -1 || nums[i] > nums[p])
            take = 1 + f(i+1, nums, i, dp);

        return dp[i][p+1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return f(0, nums, -1, dp);
    }
};