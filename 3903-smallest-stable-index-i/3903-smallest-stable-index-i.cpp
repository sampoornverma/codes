class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxi(n);
        vector<int> mini(n);

        // Prefix maximum
        int m = nums[0];
        for (int i = 0; i < n; i++) {
            m = max(m, nums[i]);
            maxi[i] = m;
        }

        // Suffix minimum
        m = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            m = min(m, nums[i]);
            mini[i] = m;
        }

        for (int i = 0; i < n; i++) {
            if (maxi[i] - mini[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};