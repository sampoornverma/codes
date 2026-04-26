class Solution {
public:
    bool dfs(int i, int j, vector<vector<bool>> &v, vector<vector<char>>& grid, int pi, int pj) {
        int n = grid.size();
        int m = grid[0].size();

        v[i][j] = true;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if(grid[ni][nj] != grid[i][j]) continue;

            if(!v[ni][nj]) {
                if(dfs(ni, nj, v, grid, i, j)) return true;
            }
            else if(ni != pi || nj != pj) {
                // visited and not parent → cycle
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> v(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!v[i][j]) {
                    if(dfs(i, j, v, grid, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};