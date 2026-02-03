class Solution {
public:
    bool a = false;
    int countIncDec = 0;
    int countDecInc = 0;

    bool isTrionic(vector<int>& nums) {
        int n = nums.size();  // Fix size bug
        if (n < 4) return false;

        // Find first increasing to decreasing transition
        int i = 1;
        while (i < n && nums[i] > nums[i-1]) {
            i++;
        }
        if (i == 1 || i == n) return false;

        // Find decreasing to increasing transition
        int j = i;
        while (j < n && nums[j] < nums[j-1]) {
            j++;
        }
        if (j == i || j == n) return false;

        // Check last part strictly increasing
        while (j < n && nums[j] > nums[j-1]) {
            j++;
        }

        return (j == n);
    }
};