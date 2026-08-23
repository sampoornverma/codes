class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int l, int u) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] < l) continue;
            if (nums[i] > u) break;

            if (nums[i] > l) {
                ans.push_back({l, nums[i] - 1});
            }

            l = nums[i] + 1;
        }

        if (l <= u) {
            ans.push_back({l, u});
        }

        return ans;
    }
};