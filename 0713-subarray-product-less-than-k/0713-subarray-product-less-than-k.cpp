class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;   // very important edge case

        int i = 0, j = 0;
        long long product = 1;
        int count = 0;

        while (j < nums.size()) {
            product *= nums[j];

            // shrink window if product >= k
            while (product >= k && i <= j) {
                product /= nums[i];
                i++;
            }

            // count subarrays ending at j
            count += (j - i + 1);
            j++;
        }
        return count;
    }
};