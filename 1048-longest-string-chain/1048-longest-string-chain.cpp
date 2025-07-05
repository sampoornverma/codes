class Solution {
public:
    // Check if 'shorter' is a valid predecessor of 'longer'
    bool isPredecessor(string& shorter, string& longer) {
        if (longer.size() != shorter.size() + 1) return false;

        int i = 0, j = 0;
        bool skipped = false;

        while (i < shorter.size() && j < longer.size()) {
            if (shorter[i] == longer[j]) {
                i++; j++;
            } else if (!skipped) {
                skipped = true;
                j++;  // skip one char from longer
            } else {
                return false;
            }
        }

        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};