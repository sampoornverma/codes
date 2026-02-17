class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        // adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);

        // {time, node}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            long long time = it.first;
            int node = it.second;

            for (auto &edge : adj[node]) {
                int next = edge.first;
                int wt = edge.second;

                // shorter path found
                if (time + wt < dist[next]) {
                    dist[next] = time + wt;
                    ways[next] = ways[node];
                    pq.push({dist[next], next});
                }
                // equal shortest path
                else if (time + wt == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
