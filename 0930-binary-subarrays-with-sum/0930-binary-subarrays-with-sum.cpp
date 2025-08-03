class Solution {
public:
    int f(vector<int>& nums, int g){
        if(g<0)return 0;
        int r=0;
        int l=0;
        int sum=0,count=0;
        while(r<nums.size()){
           sum=sum+nums[r];
           while(sum>g){
            sum=sum-nums[l];
            l++;
           }
           count=count+(r-l+1);
           r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int g) {
        return f(nums,g)-f(nums,g-1);
    }
};