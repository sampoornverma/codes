class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);   
        } 

        // {node, {distance, parent}}
        queue<pair<int, pair<int,int>>> q;

        q.push({0, {0, -1}});

        int total = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int node = it.first;
            int dist = it.second.first;
            int parent = it.second.second;

            // if apple found (except root)
            if(hasApple[node] && node != 0){
                total += 2 * dist;
                hasApple[node] = false; // avoid double counting
            }

            for(int i = 0; i < adj[node].size(); i++){
                int child = adj[node][i];

                if(child != parent){
                    q.push({child, {dist + 1, node}});
                }
            }
        }

        return total;
    }
};
