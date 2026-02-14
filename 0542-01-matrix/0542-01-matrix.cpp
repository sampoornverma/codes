class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& m1) {

        int n = m1.size();
        int m = m1[0].size();

        // {row, {col, distance}}
        queue<pair<int, pair<int,int>>> q;

        // Step 1: push all zeros and mark others as -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (m1[i][j] == 0) {
                    q.push({i, {j, 0}});
                } else {
                    m1[i][j] = -1;
                }
            }
        }

        vector<int> gr = {-1, 0, 1, 0}; 
        vector<int> gc = {0, 1, 0, -1};

        // Step 2: BFS
        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int a = it.first;
            int b = it.second.first;
            int dist = it.second.second;

            for (int i = 0; i < 4; i++) {

                int x = a + gr[i];
                int y = b + gc[i];

                if (x >= 0 && x < n && y >= 0 && y < m && m1[x][y] == -1) {

                    m1[x][y] = dist + 1;
                    q.push({x, {y, dist + 1}});
                }
            }
        }

        return m1;
    }
};