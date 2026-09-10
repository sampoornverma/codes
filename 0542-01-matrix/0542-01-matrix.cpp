class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;

        // 1. Put all 0s into the queue
        //    and mark 1s as unvisited (-1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // 2. Multi-source BFS
        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    mat[nr][nc] == -1) {

                    mat[nr][nc] = mat[r][c] + 1;

                    q.push({nr, nc});
                }
            }
        }

        return mat;
    }
};