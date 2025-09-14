class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;                // cost calculation helper
        int count = 1;                     // current window size
        long long total = nums[0];         // sum of elements in current window
        int maxi = 1;                      // max frequency
        int j = 0;                         // left pointer

        if (nums.size() == 1) return 1;

        for (int i = 1; i < nums.size(); i++) {
            total += nums[i];
            sum = (long long)(count + 1) * nums[i] - total;

            while (sum > k) {  // shrink window if cost too high
                total -= nums[j];
                j++;
                count--;
                sum = (long long)(count + 1) * nums[i] - total;
            }

            count++;
            maxi = max(maxi, count);
        }

        return maxi;
    }
};