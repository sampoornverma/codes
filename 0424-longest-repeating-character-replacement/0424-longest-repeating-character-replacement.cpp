class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, maxFreq = 0;
        vector<int> count(26, 0);
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            // If the number of chars to replace > k, shrink window
            if ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};