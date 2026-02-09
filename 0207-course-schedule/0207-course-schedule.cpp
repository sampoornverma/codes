class Solution {
public:
    // 0 = unvisited, 1 = visiting, 2 = visited
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;  // mark as visiting

        for (int nei : adj[node]) {
            if (vis[nei] == 1) {
                // cycle detected
                return false;
            }
            if (vis[nei] == 0) {
                if (!dfs(nei, adj, vis))
                    return false;
            }
        }

        vis[node] = 2;  // mark as fully processed
        return true;
    }

    bool canFinish(int v, vector<vector<int>>& pre) {
        vector<vector<int>> adj(v);
        vector<int> vis(v, 0);

        // Create adjacency list
        for (int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        // Run DFS from each unvisited node
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, adj, vis))
                    return false;
            }
        }
        return true;
    }
};