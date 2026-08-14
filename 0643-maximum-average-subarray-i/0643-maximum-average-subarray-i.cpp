class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        int sum = 0;

        int l = 0;
        int r = k;

        for(int i = 0; i < k; i++) {
            sum = sum + nums[i];
        }

        double maxsum = sum;

        while(l < r && r < n) {

            sum = sum - nums[l];
            l++;

            sum = sum + nums[r];
            r++;

            maxsum = max((double)sum, maxsum);
        }

        return maxsum / k;
    }
};