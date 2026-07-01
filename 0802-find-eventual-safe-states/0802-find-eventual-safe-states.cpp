class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<vector<int>> revAdj(V);
        vector<int> outdegree(V, 0);

        // Reverse graph and calculate outdegree
        for (int i = 0; i < V; i++) {
            outdegree[i] = graph[i].size();

            for (auto it : graph[i]) {
                revAdj[it].push_back(i);
            }
        }

        queue<int> q;

        // Terminal nodes
        for (int i = 0; i < V; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for (auto prev : revAdj[node]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0)
                    q.push(prev);
            }
        }
        sort(safe.begin(), safe.end());

        return safe;
    }
};