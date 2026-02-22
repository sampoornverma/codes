class Solution {
public:
    string maximumXor(string t, string s) {
        int z = 0, o = 0;

        // count 0s and 1s in s
        for (char c : s) {
            if (c == '0') z++;
            else o++;
        }

        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (t[i] == '0') {
                // want XOR = 1 → use '1'
                if (o > 0) {
                    ans += '1';
                    o--;
                } else {
                    ans += '0';
                    z--;
                }
            } 
            else {
                // want XOR = 1 → use '0'
                if (z > 0) {
                    ans += '1'; // XOR result
                    z--;
                } else {
                    ans += '0';
                    o--;
                }
            }
        }

        return ans;
    }
};