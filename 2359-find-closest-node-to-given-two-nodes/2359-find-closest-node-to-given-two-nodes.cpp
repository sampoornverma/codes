class Solution {
public:

    void dfs(int node, vector<int> &dist, vector<int> &vis, vector<vector<int>> &adj) {
        vis[node] = 1;

        for (auto nxt : adj[node]) {
            if (!vis[nxt]) {
                dist[nxt] = dist[node] + 1;
                dfs(nxt, dist, vis, adj);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        // build graph
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        vector<int> vis1(n, 0), vis2(n, 0);

        dist1[node1] = 0;
        dfs(node1, dist1, vis1, adj);

        dist2[node2] = 0;
        dfs(node2, dist2, vis2, adj);

        int ans = -1;
        int best = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int mx = max(dist1[i], dist2[i]);
                if (mx < best) {
                    best = mx;
                    ans = i;
                }
            }
        }

        return ans;
    }
};