class Solution {
public:
    int f(vector<int>& nums,vector<int>& dp,int i,int n){
        if(i==0)return nums[0];
        if(i<0) return 0;
        if(dp[i]!= -1) return dp[i];
        int p=nums[i]+f(nums,dp,i-2,n);
        int np=f(nums,dp,i-1,n);
        return dp[i]=max(p,np);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(nums,dp,n-1,n);
    }
};