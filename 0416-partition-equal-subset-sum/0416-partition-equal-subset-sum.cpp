class Solution {
public:
bool f(int i, int sum, vector<int>& o, vector<vector<int>>& dp, int k) {
    if (sum == k) return true;
    if (i == o.size() || sum > k) return false;

    if (dp[i][sum] != -1) return dp[i][sum];

    // pick the current element
    bool pick = f(i + 1, sum + o[i], o, dp, k);

    // don't pick the current element
    bool npick = f(i + 1, sum, o, dp, k);

    return dp[i][sum] = pick || npick;
}
    bool canPartition(vector<int>& o) {
        int n=o.size();
        int k=accumulate(o.begin(),o.end(),0);
        if(k%2 != 0)return false;
        k=k/2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(0, 0, o, dp, k);
    }
};