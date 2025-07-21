class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int n = 0;
        int a = 1;
        int count = 0;
        long long num = 0;

        while (n < size) {
            if (s[n] == '+' || s[n] == '-') {
                if (count == 0) {
                    a = (s[n] == '-') ? -1 : 1;
                    count = 1;
                } else break;
            } else if (isdigit(s[n])) {
                num = num * 10 + (s[n] - '0');
                count = 1;

                // Clamp early to avoid overflow
                if (a * num <= INT_MIN) return INT_MIN;
                if (a * num >= INT_MAX) return INT_MAX;

            } else if (count > 0) {
                break;
            } else if (s[n] != ' ') {
                break;
            }
            n++;
        }

        return a * num;
    }
};