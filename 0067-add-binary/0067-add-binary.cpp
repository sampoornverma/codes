class Solution {
public:
    string addBinary(string a1, string b) {

        int i = a1.size() - 1;
        int j = b.size() - 1;

        char carry = '0';
        string x = "";

        while (i >= 0 || j >= 0) {

            char c1 = (i >= 0) ? a1[i] : '0';
            char c2 = (j >= 0) ? b[j] : '0';

            if (c1 != c2) {
                if (carry == '1') {
                    x = x + '0';
                    carry = '1';
                } else {
                    x = x + '1';
                    carry = '0';
                }
            } 
            else {
                if (c1 == '1') {
                    if (carry == '1') {
                        x = x + '1';
                        carry = '1';
                    } else {
                        x = x + '0';
                        carry = '1';
                    }
                } 
                else {
                    x = x + carry;
                    carry = '0';
                }
            }

            i--;
            j--;
        }

        if (carry == '1') {
            x = x + '1';
        }

        reverse(x.begin(), x.end());
        return x;
    }
};