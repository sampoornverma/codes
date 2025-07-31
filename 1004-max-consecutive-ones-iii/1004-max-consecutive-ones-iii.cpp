class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int l=0;
    int r=0;
    int one=0;
    int len=0;
    while(r<nums.size()){
        if(nums[r]==0)one++;
        if(one>k){
            if(nums[l]==0)one--;
            l++;
            }
        else{
        
        len=max(len,r-l+1);}
        r++;
    }
    return len;  
    }
};