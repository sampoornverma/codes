class Solution {
public:
    void dfs(vector<vector<char>>& grid,
             vector<vector<int>>& vis,
             int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        // Base cases
        if (i < 0 || j < 0 || i >= n || j >= m ||
            grid[i][j] == '0' || vis[i][j] == 1)
            return;

        vis[i][j] = 1;

        // 4-directional DFS
        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i - 1, j); // up
        dfs(grid, vis, i, j + 1); // right
        dfs(grid, vis, i, j - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    count++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};