class Solution {
public:
    int f(vector<int>& nums, int k) {
        int r = 0, l = 0;
        map<int, int> mp;
        int count = 0;
        while (r < nums.size()) {
            mp[nums[r]]++;
            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};