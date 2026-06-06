class Solution {
public:
    int f(vector<int>& nums, int target,vector<int> &dp){

        // if(i>=nums.size())return 0;
        if(target<0)return 0;
        if(target==0)return 1;
        int sum=0;
        if(dp[target]!= -1)return dp[target];
        for(int i=0;i<nums.size();i++){
            int take=0;
            if(nums[i]<=target) take=f(nums,target-nums[i],dp);
            sum=sum+take;
        }
        return dp[target]=sum;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return f(nums,target,dp);
    }
};