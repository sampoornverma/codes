class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> mp;
        int xy=0;
        int i = 0;
        int maxi = 0;
        int n = nums.size();

        for(int j = 0; j < n; j++) {
            mp[nums[j]]++;

            while(mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }

            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};