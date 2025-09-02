class d {
public:
    vector<int> rank, parent;
    d(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int n) {
        if (n == parent[n]) return n;
        return parent[n] = findparent(parent[n]);
    }

    void unionByRank(int u, int v) {
        int up = findparent(u);
        int vp = findparent(v);
        if (up == vp) return;
        if (rank[up] < rank[vp]) {
            parent[up] = vp;
        } else if (rank[up] > rank[vp]) {
            parent[vp] = up;
        } else {
            parent[vp] = up;
            rank[up]++;
        }
    }
};

class Solution {
public:
    bool valid(int a, int b, int n) {
        return (a < n && a >= 0 && b < n && b >= 0);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        d ds(n*n);

        // directions
        vector<int> r = {-1, 0, 1, 0};
        vector<int> c = {0, 1, 0, -1};

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxi = max(maxi, grid[i][j]);
            }
        }

        // simulate rising water
        for (int t = 0; t <= maxi; t++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] <= t) {
                        int node1 = i*n + j;
                        for (int k = 0; k < 4; k++) {
                            int r0 = i + r[k];
                            int c0 = j + c[k];
                            if (valid(r0, c0, n) && grid[r0][c0] <= t) {
                                int node2 = r0*n + c0;
                                ds.unionByRank(node1, node2);
                            }
                        }
                    }
                }
            }
            if (ds.findparent(0) == ds.findparent(n*n - 1)) {
                return t;
            }
        }
        return maxi;
    }
};