class Solution {
public:
    int f(vector<int>& nums, int k){
    int count=0;
    int l=0;
    int r=0,count1=0;
    while(r<nums.size()){
        if(nums[r]%2 ==1)count++;
        while(count>k){
            if(nums[l]%2 == 1)count--;
            l++;
        }
        count1=count1+(r-l)+1;
        r++;
    }
    return  count1; 
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};