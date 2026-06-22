class Solution {
public:
    bool valid(long long sum, int x) {
        if (sum % 10 != x) return false;   // last digit

        while (sum >= 10) {
            sum /= 10;
        }

        return sum == x;                   // first digit
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (valid(sum, x))
                    count++;
            }
        }

        return count;
    }
};