class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k==0)return 0;
    int i=0;
    int j=0;
    int product=1;
    int count=0;
    while(j<nums.size() && i<=j){
        product=product*nums[j];
        while(product>=k  && i<=j){
            product=product/nums[i];
            i++;
        }
        
        count=count+j-i+1;
        j++;
    }
    return count;    
    }
};