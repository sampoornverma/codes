class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);

        // build graph
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while (!q.empty()) {

            int it = q.front();
            q.pop();

            if (it == destination) return true;

            for (auto &p : adj[it]) {
                if (!vis[p]) {
                    vis[p] = 1;
                    q.push(p);
                }
            }
        }

        return false;
    }
};