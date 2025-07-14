class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adj(v);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(v, 0);
        int count = 0;
        for (int i = 0; i < v; ++i) {
            if (!vis[i]) {
                count++;
                dfs(i, vis, adj);
            }
        }

        return count;
    }
};