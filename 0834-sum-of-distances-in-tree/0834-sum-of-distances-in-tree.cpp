class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> res(n, 0);

        // Run a BFS for every single node
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, -1);
            queue<int> q;
            
            q.push(i);
            dist[i] = 0;
            int currentSum = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                currentSum += dist[u];

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            res[i] = currentSum;
        }

        return res;
    }
};