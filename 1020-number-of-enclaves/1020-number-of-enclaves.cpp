class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<int>& dr, vector<int>& dc) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;

        for (int d = 0; d < 4; d++) {
            int r = i + dr[d];
            int c = j + dc[d];
            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1) {
                dfs(r, c, vis, grid, dr, dc);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // Traverse boundary rows
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !vis[0][j])
                dfs(0, j, vis, grid, dr, dc);
            if (grid[n - 1][j] == 1 && !vis[n - 1][j])
                dfs(n - 1, j, vis, grid, dr, dc);
        }

        // Traverse boundary columns
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, vis, grid, dr, dc);
            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(i, m - 1, vis, grid, dr, dc);
        }

        int count = 0;
        // Count all unvisited land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }

        return count;
    }
};