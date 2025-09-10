class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        long long count = 1;
        int MOD = 1e9 + 7;

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                count++; // extend streak
            } else {
                // streak ends → add substrings
                ans = (ans + (count * (count + 1) / 2) % MOD) % MOD;
                count = 1; // reset for next streak
            }
        }
        return ans % MOD;
    }
};