class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;

        for (int start = 0; start < n; start++) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;

            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei : adj[node]) {
                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        parent[nei] = node;
                        q.push(nei);
                    }
                    else if (parent[node] != nei) {
                        ans = min(ans, dist[node] + dist[nei] + 1);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};