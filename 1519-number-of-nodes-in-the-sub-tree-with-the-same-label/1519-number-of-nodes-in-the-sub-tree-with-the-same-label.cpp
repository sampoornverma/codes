class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj,
             int curr,
             int parent,
             vector<int> &result,
             string &labels,
             vector<int> &count) {

        char myLabel = labels[curr];

        int count_before_visiting_curr_children = count[myLabel - 'a'];

        // explore children
        count[myLabel - 'a'] += 1;

        for (int &v : adj[curr]) {
            if (v == parent) continue;

            DFS(adj, v, curr, result, labels, count);
        }

        int count_after_visiting_curr_children = count[myLabel - 'a'];

        result[curr] =
            count_after_visiting_curr_children - count_before_visiting_curr_children;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        // ✅ use unordered_map because DFS uses it
        unordered_map<int, vector<int>> adj;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> ans(n, 0);
        vector<int> count(26, 0);

        // ✅ correct call
        DFS(adj, 0, -1, ans, labels, count);

        return ans;
    }
};