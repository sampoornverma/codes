class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // Initialize queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0; // No fresh oranges to rot

        vector<int> gr = {-1, 0, 1, 0};
        vector<int> gc = {0, 1, 0, -1};

        int minutes = -1;

        while (!q.empty()) {
            int levelSize = q.size();
            minutes++;
            for (int i = 0; i < levelSize; i++) {
                auto [r, c] = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + gr[d];
                    int nc = c + gc[d];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};