class Solution {
public:

    void dfs(vector<vector<int>>& vis, vector<vector<int>>& a, int i, int j) {

        int n = a.size();
        int m = a[0].size();

        vis[i][j] = 1;

        // check all stones in same row
        for (int col = 0; col < m; col++) {
            if (a[i][col] == 1 && !vis[i][col]) {
                dfs(vis, a, i, col);
            }
        }

        // check all stones in same column
        for (int row = 0; row < n; row++) {
            if (a[row][j] == 1 && !vis[row][j]) {
                dfs(vis, a, row, j);
            }
        }
    }


    int removeStones(vector<vector<int>>& s) {

        int maxr = 0, maxc = 0;

        for (auto &x : s) {
            maxr = max(maxr, x[0]);
            maxc = max(maxc, x[1]);
        }

        // grid
        vector<vector<int>> a(maxr + 1, vector<int>(maxc + 1, 0));

        for (auto &x : s) {
            a[x[0]][x[1]] = 1;
        }

        vector<vector<int>> vis(maxr + 1, vector<int>(maxc + 1, 0));

        int components = 0;

        for (auto &x : s) {
            int i = x[0], j = x[1];

            if (!vis[i][j]) {
                components++;
                dfs(vis, a, i, j);
            }
        }

        return s.size() - components;
    }
};