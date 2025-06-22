class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& o) {
        int n = o.size();
        vector<int> prev = o[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                int down = prev[j];
                int left = (j > 0) ? prev[j - 1] : 1e9;
                int right = (j < n - 1) ? prev[j + 1] : 1e9;

                curr[j] = o[i][j] + min(down, min(left, right));
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};