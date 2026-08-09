class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxi = 0;

        // Your DP
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 1) {

                    if (i == 0 || j == 0) {
                        mat[i][j] = 1;
                    }
                    else {
                        mat[i][j] = 1 + min(
                            mat[i-1][j],
                            min(mat[i-1][j-1], mat[i][j-1])
                        );
                    }

                    maxi = max(maxi, mat[i][j]);
                }
            }
        }

        // size -> positions of squares having at least this size
        unordered_map<int, vector<pair<int,int>>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] > 0) {

                    int k = mat[i][j];

                    // Top-left corner of the largest square
                    int r = i - k + 1;
                    int c = j - k + 1;

                    mp[k].push_back({r, c});
                }
            }
        }

        priority_queue<int> pq;

        for (auto &it : mp) {
            pq.push(it.first);
        }

        while (!pq.empty()) {

            int k = pq.top();
            pq.pop();

            auto &v = mp[k];

            for (int i = 0; i < v.size(); i++) {
                for (int j = i + 1; j < v.size(); j++) {

                    int r1 = v[i].first;
                    int c1 = v[i].second;

                    int r2 = v[j].first;
                    int c2 = v[j].second;

                    if (abs(r1 - r2) >= k) {
                        return k * k;
                    }

                    if (abs(c1 - c2) >= k) {
                        return k * k;
                    }
                }
            }
        }

        return 0;
    }
};