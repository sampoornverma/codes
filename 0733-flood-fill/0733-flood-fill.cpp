class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();
        int original = image[sr][sc];

        // Important edge case
        if (original == color) return image;

        vector<int> gr = {-1, 0, 1, 0}; 
        vector<int> gc = {0, 1, 0, -1};

        queue<pair<int,int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int x = it.first;
            int y = it.second;

            image[x][y] = color;

            for (int i = 0; i < 4; i++) {
                int a = x + gr[i];
                int b = y + gc[i];

                if (a >= 0 && a < n && b >= 0 && b < m && image[a][b] == original) {
                    q.push({a, b});
                }
            }
        }

        return image;
    }
};