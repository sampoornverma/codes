class Solution {
public:
    bool dfs(int i, int j, int k,
             vector<vector<char>>& board,
             vector<vector<bool>>& vis,
             string& word) {

        if (k == word.size())
            return true;

        int n = board.size();
        int m = board[0].size();

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int d = 0; d < 4; d++) {
            int ni = i + dr[d];
            int nj = j + dc[d];

            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m &&
                !vis[ni][nj] &&
                board[ni][nj] == word[k]) {

                vis[ni][nj] = true;

                if (dfs(ni, nj, k + 1, board, vis, word))
                    return true;

                vis[ni][nj] = false; // backtrack
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0]) {
                    vis[i][j] = true;

                    if (dfs(i, j, 1, board, vis, word))
                        return true;

                    vis[i][j] = false;
                }
            }
        }

        return false;
    }
};