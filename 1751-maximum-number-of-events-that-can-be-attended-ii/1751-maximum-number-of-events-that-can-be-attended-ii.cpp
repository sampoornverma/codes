class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by startDay

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Binary search helper to find next event's index
        auto findNext = [&](int currEnd) {
            int low = 0, high = n;
            while (low < high) {
                int mid = (low + high) / 2;
                if (events[mid][0] > currEnd)
                    high = mid;
                else
                    low = mid + 1;
            }
            return low;
        };

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                int next = findNext(events[i][1]); // first non-overlapping event
                dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[next][j - 1]);
            }
        }

        return dp[0][k];
    }
};