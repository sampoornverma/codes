class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findparent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findparent(parent[x]);
    }

    void unionBySize(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    bool valid(int a, int b, int n) {
        return (a < n && a >= 0 && b < n && b >= 0);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        int maxi = 0;

        vector<int> r = {-1, 0, 1, 0};
        vector<int> c = {0, 1, 0, -1};

        // Step 1: Union all existing 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int row = i + r[k];
                        int col = j + c[k];
                        if (valid(row, col, n) && grid[row][col] == 1) {
                            int node1 = i*n + j;
                            int node2 = row*n + col;
                            ds.unionBySize(node1, node2);
                        }
                    }
                }
            }
        }

        // Step 2: Try flipping each 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> comps;
                    for (int k = 0; k < 4; k++) {
                        int row = i + r[k];
                        int col = j + c[k];
                        if (valid(row, col, n) && grid[row][col] == 1) {
                            comps.insert(ds.findparent(row*n + col));
                        }
                    }
                    int count = 1; // flip current 0 → 1
                    for (auto p : comps) {
                        count += ds.size[p];
                    }
                    maxi = max(maxi, count);
                }
            }
        }

        for (int i = 0; i < n*n; i++) {
            if (ds.findparent(i) == i) {
                maxi = max(maxi, ds.size[i]);
            }
        }

        return maxi;
    }
};