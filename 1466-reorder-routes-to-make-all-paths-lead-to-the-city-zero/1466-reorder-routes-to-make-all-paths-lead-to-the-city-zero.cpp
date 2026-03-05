class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> adj(n);

        // build graph
        for(auto &e : connections){
            int a = e[0], b = e[1];

            adj[a].push_back({b, 1}); // original direction
            adj[b].push_back({a, 0}); // reverse direction
        }

        vector<bool> visited(n, false);
        return dfs(0, adj, visited);
    }

    int dfs(int node, vector<vector<pair<int,int>>> &adj, vector<bool> &visited){
        visited[node] = true;
        int changes = 0;

        for(auto &it : adj[node]){
            int neigh = it.first;
            int cost = it.second;

            if(!visited[neigh]){
                changes += cost;
                changes += dfs(neigh, adj, visited);
            }
        }

        return changes;
    }
};