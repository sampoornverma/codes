class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> arr(2001, 0);  // safer than 1001
        
        // Fill frequency array using nums, not cin
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 2000)
                arr[nums[i]] = 1;
        }

        int x = original;
        while (x <= 2000 && arr[x] == 1) {
            x = x * 2;
        }
        return x;
    }
};