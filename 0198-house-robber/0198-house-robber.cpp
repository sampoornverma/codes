class Solution {
public:
    int f(vector<int> &dp,int i,vector<int>& nums){
        if(i>=nums.size())return 0;
        if(i==nums.size()-1)return nums[i];
        if(dp[i]!= -1)return dp[i];
        return dp[i]=max(nums[i]+f(dp,i+2,nums),f(dp,i+1,nums));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(dp,0,nums); 
    }
};