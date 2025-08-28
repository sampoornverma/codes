class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int x) {
        // Step 1: Initialize distance matrix
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) dis[i][i] = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dis[u][v] = w;
            dis[v][u] = w;
        }

        // Step 2: Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        // Step 3: Count reachable cities
        vector<int> c(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dis[i][j] <= x) {
                    c[i]++;
                }
            }
        }

        // Step 4: Find city with smallest count (break ties by largest index)
        int ans = -1, minReach = 1e9;
        for (int i = 0; i < n; i++) {
            if (c[i] <= minReach) {
                minReach = c[i];
                ans = i; // choose largest index in case of tie
            }
        }

        return ans;
    }
};