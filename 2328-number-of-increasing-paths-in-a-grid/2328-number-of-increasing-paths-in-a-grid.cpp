class Solution {
public:
    int mod = 1e9 + 7;
    int n, m;
    vector<vector<int>> dp;

    int f(vector<vector<int>>& grid, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1; // path of length 1 (itself)

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] > grid[i][j]){
                ans = (ans + f(grid, ni, nj)) % mod;
            }
        }

        return dp[i][j] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<int>(m, -1));

        int res = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res = (res + f(grid, i, j)) % mod;
            }
        }

        return res;
    }
};