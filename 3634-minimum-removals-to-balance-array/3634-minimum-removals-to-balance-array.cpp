class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if (n <= 1) return 0;

        int i = 0;
        int j = 1;
        int maxi = 1;

        while (j < n) {
            if ((long long)nums[i] * k >= nums[j]) {
                // valid window, expand
                maxi = max(maxi, j - i + 1);
                j++;
            } else {
                // invalid window, shrink from left ONLY
                i++;
            }
        }

        return n - maxi;
    }
};