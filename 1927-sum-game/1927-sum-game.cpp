class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?')
                    leftQ++;
                else
                    leftSum += num[i] - '0';
            } 
            else {
                if (num[i] == '?')
                    rightQ++;
                else
                    rightSum += num[i] - '0';
            }
        }

        if ((leftQ + rightQ) % 2 == 1)
            return true;

        if (leftSum - rightSum == (rightQ - leftQ) * 9 / 2)
            return false;

        return true;
    }
};