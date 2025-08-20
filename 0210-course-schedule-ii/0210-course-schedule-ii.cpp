class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& edges) {
    vector<vector<int>> adj(v);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<int> indegree(v, 0);
        vector<int> r;
        vector<int> r1;
        for (int i = 0; i < edges.size(); i++) {
            indegree[edges[i][1]]++;
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0; 
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            r.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        reverse(r.begin(),r.end());
        if(r.size()==v)return r; 
        return r1; 
    }
};