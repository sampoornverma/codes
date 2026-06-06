class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int rightSum = 0;
        int leftSum = 0;
        
        // Calculate the total sum of the array first
        for (int num : nums) {
            rightSum += num;
        }
        
        // Iterate and calculate the differences on the fly
        for (int i = 0; i < n; i++) {
            // 1. The current element is no longer on the right
            rightSum -= nums[i]; 
            
            // 2. Calculate the difference
            ans[i] = abs(leftSum - rightSum);
            
            // 3. Add the current element to leftSum for the next iteration
            leftSum += nums[i];  
        }
        
        return ans;
    }
};