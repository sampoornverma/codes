class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int> arr(nums.begin(), nums.end());

        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        while (arr.find(sum) != arr.end()) {
            sum++;
        }

        return sum;
    }
};