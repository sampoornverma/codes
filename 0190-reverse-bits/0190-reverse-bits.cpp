class Solution {
public:
    int reverseBits(int n) {

        string s = "";

        // Step 1: get 32-bit binary
        for (int i = 31; i >= 0; i--) {
            int x = ((n >> i) & 1);
            s += char('0' + x);
        }
        reverse(s.begin(),s.end());
        // Step 2: convert reversed bits to number
        unsigned int x = 0;
        unsigned int n1 = 1;

        for (int i = 31; i >= 0; i--) {
            x += n1 * (s[i] - '0');
            n1 *= 2;
        }

        return x;
    }
};