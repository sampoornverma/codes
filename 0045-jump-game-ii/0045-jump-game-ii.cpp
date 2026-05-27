class Solution {
public:
    int f(int j,vector<int>& nums,vector<int> &dp){
        if(j==nums.size()-1) return 0;
        int count=nums.size();
        if(dp[j]!= -1)return dp[j];
        for(int i=1;i<=nums[j] && j+i<nums.size();i++){
            count=min(count,1+f(j+i,nums,dp));
        }
        return dp[j]=count;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
       return f(0,nums,dp); 
    }
};