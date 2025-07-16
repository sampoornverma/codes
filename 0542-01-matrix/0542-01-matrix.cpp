class Solution {
public:
    void bfs(int n, int m, vector<vector<int>>& img, vector<int> gc, vector<int> gr) {
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (img[i][j] == 0) {
                    q.push({i, j});
                } else {
                    img[i][j] = -1; // mark unvisited 1s
                }
            }
        }

        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int af = a + gr[i];
                int bf = b + gc[i];

                if (af >= 0 && bf >= 0 && af < n && bf < m && img[af][bf] == -1) {
                    img[af][bf] = img[a][b] + 1;
                    q.push({af, bf});
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> img = mat;
        vector<int> gc = {-1, 0, 1, 0};
        vector<int> gr = {0, -1, 0, 1};
        int n = mat.size();
        int m = mat[0].size();
        bfs(n, m, img, gc, gr);
        return img;
    }
};
