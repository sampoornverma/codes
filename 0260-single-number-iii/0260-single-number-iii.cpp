class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans;

        // first element
        if (nums[0] != nums[1]) {
            ans.push_back(nums[0]);
        }

        // middle elements
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
                ans.push_back(nums[i]);
            }
        }

        // last element
        if (nums[n - 1] != nums[n - 2]) {
            ans.push_back(nums[n - 1]);
        }

        return ans;
    }
};