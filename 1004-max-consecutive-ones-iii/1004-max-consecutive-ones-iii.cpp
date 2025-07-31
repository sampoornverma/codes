class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int l=0;
    int r=0;
    int one=0;
    int len=0,x=nums.size();
    while(r<x){
        if(nums[r]==0)one++;
        while(one>k){
            if(nums[l]==0)one--;
            l++;
            }
        
        
        len=max(len,r-l+1);
        r++;
    }
    return len;  
    }
};