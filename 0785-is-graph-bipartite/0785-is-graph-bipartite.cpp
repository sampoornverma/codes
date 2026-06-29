class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for (int start = 0; start < graph.size(); start++) {

            if (color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei : graph[node]) {
                    if (color[nei] == -1) {
                        color[nei] = !color[node];
                        q.push(nei);
                    } else if (color[nei] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};