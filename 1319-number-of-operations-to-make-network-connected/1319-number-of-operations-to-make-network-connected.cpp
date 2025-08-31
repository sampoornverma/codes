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

    void unionByRank(int u, int v) {   // renamed union → unionByRank
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
    int makeConnected(int n, vector<vector<int>>& c) {
        if (c.size() < n - 1) return -1;  // not enough edges

        d ds(n);
        int count = 0;
        int x = 0;

        for (auto &it : c) {
            int u = it[0];   // use it[0], it[1] instead of .first/.second
            int v = it[1];
            if (ds.findparent(u) == ds.findparent(v)) {
                count++;  // extra edge
            } else {
                x++;
                ds.unionByRank(u, v);
            }
        }

        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findparent(i) == i) comp++;
        }

        int needed = comp - 1;
        if (count >= needed) return needed;
        return -1;
    }
};