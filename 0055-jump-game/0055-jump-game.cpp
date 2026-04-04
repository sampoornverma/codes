class Solution {
public:
    
    bool f(int i, vector<int>& nums, vector<int>& dp){

        if(i >= nums.size()-1) return true;

        if(nums[i] == 0) return false;

        if(dp[i] != -1) return dp[i];

        for(int j = 1; j <= nums[i]; j++){
            if(f(i + j, nums, dp))
                return dp[i] = 1;
        }

        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, -1);

        return f(0, nums, dp);
    }
};