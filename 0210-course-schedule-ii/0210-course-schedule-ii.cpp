class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& pre) {
            vector<vector<int>> adj(v);  // initialize adj with size v

        // Create adjacency list
        for (int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]); // Reverse edge: course B → course A
        }

        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++) {
            for (int j : adj[i]) {
                indegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int>a;
        vector<int>b;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            a.push_back(node);
            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        if(a.size()==v)return a;
        else return b;  
    }
};