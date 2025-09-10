class Solution {
public:
    int myAtoi(string s) {
        int count = 0;
        string s1 = "";
        char sign = '+';
        
        for (char c : s) {
            if (!count && c != ' ') {
                if (c == '+' || c == '-') {
                    sign = c;
                    count++;
                    continue; // skip storing sign into s1
                }
                count++;
            }
            
            if (isalpha(c) || (count && c == ' ') || (count && c == '+') || (count && c == '-')) {
                break;
            } else {
                s1 = s1 + c;
            }
        }
        
        if (s1 == "") return 0;
        
        long long final = 0; // use long long to check overflow
        for (char c : s1) {
            int a = c - '0';
            final = final * 10 + a;
            
            if (sign == '+' && final > INT_MAX) return INT_MAX;
            if (sign == '-' && -final < INT_MIN) return INT_MIN;
        }
        
        return (sign == '-') ? -final : final;
    }
};