class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    void dsu(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int u) {
        if (parent[u] == u)
            return u;

        return parent[u] = findparent(parent[u]);
    }

    void unionrank(int u, int v) {
        u = findparent(u);
        v = findparent(v);

        if (u == v)
            return;

        if (rank[u] > rank[v]) {
            parent[v] = u;
        }
        else if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    bool equationsPossible(vector<string>& e) {
        dsu(26);

        // First pass: process all equalities
        for (int i = 0; i < e.size(); i++) {
            int a = e[i][0] - 'a';
            int b = e[i][3] - 'a';

            if (e[i][1] == '=') {
                unionrank(a, b);
            }
        }

        // Second pass: check all inequalities
        for (int i = 0; i < e.size(); i++) {
            int a = e[i][0] - 'a';
            int b = e[i][3] - 'a';

            if (e[i][1] == '!') {
                if (findparent(a) == findparent(b)) {
                    return false;
                }
            }
        }

        return true;
    }
};