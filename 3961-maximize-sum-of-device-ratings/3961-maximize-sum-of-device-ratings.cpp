class Solution {
public:
    long long maxRatings(vector<vector<int>>& a) {
        long long ans = 0;
        int n = a.size(), m = a[0].size();
        if (m == 1) {
            for (int i = 0; i < n; i++) ans += a[i][0];
            return ans;
        }
        int mn = INT_MAX;
        int d = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mn = min(mn, a[i][j]);
            }
        }
        int mnt = INT_MAX;
        for (int i = 0; i < n; i++) {
            sort(a[i].begin(), a[i].end());
            ans += a[i][1];
            mnt = min(mnt, a[i][1]);
        }

        ans -= mnt;
        ans += mn;
        return ans;
    }
};