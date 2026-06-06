class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int i, vector<int>& nums, string& s, int taken) {
        int n = s.size();
        if (i >= n)
            return 0;
        if (dp[i][taken] != -1)
            return dp[i][taken];

        long long ans = solve(i + 1, nums, s, 0);

        if (s[i] == '1' && !taken) {
            ans = max(ans, 1LL * nums[i] + solve(i + 1, nums, s, 0));
        }
        if (i + 1 < n && s[i + 1] == '1') {
            ans = max(ans, 1LL * nums[i] + solve(i + 1, nums, s, 1));
        } 
        return dp[i][taken] = ans;
    }
    long long maxTotal(vector<int>& nums, string s) {
        int n = s.size();
        dp.assign(n, vector<long long>(2,-1));

        return solve(0, nums, s, 0);
    }
};