class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prev = 0;   // previous block count
        int curr = 1;   // current block count
        int total = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                curr++;   // extend current block
            } else {
                // like going from 00111 → 11100
                total += min(prev, curr);
                prev = curr;   // save previous group
                curr = 1;
            }
        }

        total += min(prev, curr);
        return total;
    }
};