class Solution {
public:
    int n;
    unordered_map<int,int> pos;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& arr) {
        if (dp[i][j] != -1)
            return dp[i][j];

        long long next = 1LL * arr[i] + arr[j];

        if (!pos.count(next))
            return dp[i][j] = 2;

        int k = pos[next];

        return dp[i][j] = 1 + solve(j, k, arr);
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();

        for (int i = 0; i < n; i++)
            pos[arr[i]] = i;

        dp.assign(n, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, solve(i, j, arr));
            }
        }

        return ans >= 3 ? ans : 0;
    }
};