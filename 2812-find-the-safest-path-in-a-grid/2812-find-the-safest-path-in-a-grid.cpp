class Solution {
public:
    bool isPossible(vector<vector<int>>& dist, int sf) {
        int n = dist.size();

        if (dist[0][0] < sf) return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0,0});
        vis[0][0] = 1;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            if (r == n-1 && c == n-1)
                return true;

            for (int k=0;k<4;k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr>=0 && nr<n && nc>=0 && nc<n &&
                    !vis[nr][nc] &&
                    dist[nr][nc] >= sf) {

                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            for (int k=0;k<4;k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr>=0 && nr<n && nc>=0 && nc<n &&
                    dist[nr][nc] == INT_MAX) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }

        int low = 0;
        int high = 2 * n;   // Maximum possible Manhattan distance
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(dist, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};