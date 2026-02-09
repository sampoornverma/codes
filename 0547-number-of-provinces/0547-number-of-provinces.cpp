class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int city, vector<int>& vis) {
        vis[city] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[city][j] == 1 && vis[j] == 0) {
                dfs(isConnected, j, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                count++;
                dfs(isConnected, i, vis);
            }
        }
        return count;
    }
};