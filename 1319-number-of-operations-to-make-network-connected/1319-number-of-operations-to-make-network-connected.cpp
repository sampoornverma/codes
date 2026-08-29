class dsu {
public:
    vector<int> size;
    vector<int> parent;

    dsu(int n) {
        size.assign(n, 1);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u)
            return u;

        return parent[u] = find(parent[u]); // path compression
    }

    void unioni(int u, int v) {
        int x = find(u);
        int y = find(v);

        if (x == y)
            return;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        dsu d(n);

        int extraEdges = 0;

        for (int i = 0; i < connections.size(); i++) {
            int l = connections[i][0];
            int b = connections[i][1];

            int x = d.find(l);
            int y = d.find(b);

            if (x == y) {
                extraEdges++;
            } else {
                d.unioni(l, b);
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (d.find(i) == i)
                components++;
        }

        int needed = components - 1;

        return extraEdges >= needed ? needed : -1;
    }
};