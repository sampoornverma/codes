class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        // 1) Strictly increasing part
        int p = 0;
        while (p < n - 2 && nums[p] < nums[p + 1]) {
            p++;
        }
        // No initial strictly increasing part
        if (p == 0) return false;

        // 2) Strictly decreasing part
        int q = p;
        while (q < n - 1 && nums[q] > nums[q + 1]) {
            q++;
        }
        // Must be a decreasing segment and room for final increase
        if (q == p || q == n - 1) return false;

        // 3) Final strictly increasing part
        while (q < n - 1 && nums[q] < nums[q + 1]) {
            q++;
        }

        // Check if we reached the end
        return (q == n - 1);
    }
};