class DSU {
public:
    vector<int> rank, parent;
    DSU(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) parent[i] = i;
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto &s : stones) {
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }

        int offset = maxRow + 1;
        DSU ds(maxRow + maxCol + 2);

        // Union rows and columns for each stone
        for (auto &s : stones) {
            int rowNode = s[0];
            int colNode = s[1] + offset;
            ds.unionByRank(rowNode, colNode);
        }

        // Count unique connected components
        unordered_set<int> comps;
        for (auto &s : stones) {
            int node = ds.findparent(s[0]);  // row representative is enough
            comps.insert(node);
        }

        return stones.size() - comps.size(); 
    }
};