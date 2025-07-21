#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;  // Start coloring with 0

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node]; // Alternate color
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false; // Same color on both sides — not bipartite
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1); // -1 means unvisited

        for (int i = 0; i < v; ++i) {
            if (color[i] == -1) {
                if (!bfs(i, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};