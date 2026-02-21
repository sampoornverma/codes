class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count1 = 0;

        for (int i = left; i <= right; i++) {
            int count = __builtin_popcount(i);
            bool prime = true;

            if (count < 2) prime = false;

            for (int j = 2; j <= count / 2; j++) {
                if (count % j == 0) {
                    prime = false;
                    break;
                }
            }

            if (prime) count1++;
        }

        return count1;
    }
};