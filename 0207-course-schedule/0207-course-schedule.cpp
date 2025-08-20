class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& edges) {
    vector<vector<int>> adj(v);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        // Compute indegrees
        vector<int> indegree(v, 0);
        for (int i = 0; i < edges.size(); i++) {
            indegree[edges[i][1]]++;
        }

        // Push all nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0; // count nodes in topo sort
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        // If count < v, cycle exists
        return (count == v);   
    }
};