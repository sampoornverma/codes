class Solution {
public:

    void dfs(int node, vector<vector<int>>& rooms, vector<int>& vis) {
        vis[node] = 1;

        for (auto &key : rooms[node]) {
            if (!vis[key]) {
                dfs(key, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<int> vis(n, 0);

        dfs(0, rooms, vis);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }

        return true;
    }
};