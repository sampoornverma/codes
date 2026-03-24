class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int mini= -1e4;
    int maxi= -1e4;
    for(int i=0;i<nums.size();i++){
        if(mini<0)mini=0;
        if(mini+nums[i]<0)mini=nums[i];
        else mini=mini + nums[i];
        
        maxi=max(maxi,mini);
        
    }
    return maxi;
    }
};