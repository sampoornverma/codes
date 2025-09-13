class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;           // sum of elements in window [i..j]
        int ans = 0;
        int j = nums.size() - 1;       // right pointer (largest in window)

        for (int i = nums.size() - 1; i >= 0; --i) {
            total += nums[i];

            // target is nums[j] (largest in window [i..j])
            while (j >= i && (long long)nums[j] * (j - i + 1) - total > k) {
                total -= nums[j];
                j--;
            }

            if (j >= i) ans = max(ans, j - i + 1);
        }

        return ans;
    }
};