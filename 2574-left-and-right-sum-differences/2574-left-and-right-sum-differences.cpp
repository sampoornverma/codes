class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int rightSum = 0;
        int leftSum = 0;
        
        for (int num : nums) {
            rightSum += num;
        }
        
        for (int i = 0; i < n; i++) {
            rightSum -= nums[i]; 
            
            ans[i] = abs(leftSum - rightSum);
            
            leftSum += nums[i];  
        }
        
        return ans;
    }
};