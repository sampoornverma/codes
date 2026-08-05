class Solution {
public:
    int x;

    void dfs(int k, vector<vector<int>> &adj, vector<int> &vis) {
        vis[k] = x;

        for (int g : adj[k]) {
            if (vis[g] != x) {
                dfs(g, adj, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {

        vector<vector<int>> adj(n);

        for (int i = 0; i < in.size(); i++) {
            adj[in[i][0]].push_back(in[i][1]);
        }

        vector<int> vis(n, -1);

        x = 2;
        dfs(k, adj, vis);
        for (int i = 0; i < in.size(); i++) {
            int u = in[i][0];
            int v = in[i][1];

            if (vis[u] == -1 && vis[v] == 2) {
                vector<int> ans;
                for (int j = 0; j < n; j++)
                    ans.push_back(j);
                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1)
                ans.push_back(i);
        }

        return ans;
    }
};