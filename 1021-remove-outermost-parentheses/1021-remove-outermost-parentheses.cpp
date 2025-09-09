class Solution {
public:
    string removeOuterParentheses(string s) {
        int x = 0; // count of '('
        int y = 0; // count of ')'
        string s1 = "";

        for (char a : s) {
            if (a == '(') {
                if (x > y) {       // not outermost
                    s1 += a;
                }
                x++;
            } else { // a == ')'
                y++;
                if (x > y) {       // not outermost
                    s1 += a;
                }
            }
        }
        return s1;
    }
};