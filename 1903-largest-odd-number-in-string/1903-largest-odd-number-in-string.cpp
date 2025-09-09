class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int ind = -1;

        for (int i = n - 1; i >= 0; i--) {
            int a = num[i] - '0';  
            if (a % 2 == 1) {
                ind = i;
                break;
            }
        }

        if (ind == -1) return "";    
        return num.substr(0, ind + 1); 
    }
};