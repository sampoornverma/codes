class Solution {
public:
    int maxi = 1;

    int dfs(int node, int parent, vector<vector<int>> &adj, string &s) {
        int best1 = 0, best2 = 0;  
        for (int i = 0; i < adj[node].size(); i++) {
            int child = adj[node][i];

            if (child == parent) continue;

            int childLen = dfs(child, node, adj, s);

            if (s[child] != s[node]) {
                if (childLen > best1) {
                    best2 = best1;
                    best1 = childLen;
                } else if (childLen > best2) {
                    best2 = childLen;
                }
            }
        }

        maxi = max(maxi, best1 + best2 + 1);

        return best1 + 1;
    }

    int longestPath(vector<int>& p, string s) {
        int n = s.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
            adj[i].push_back(p[i]);
        }

        dfs(0, -1, adj, s);

        return maxi;
    }
};