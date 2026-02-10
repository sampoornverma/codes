class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    if(k==0)return 0;
    long long i=0;
    long long j=0;
    long long product=0;
    long long count=0;
    while(j<nums.size() && i<=j){
        product=product+nums[j];
        while(product*(j-i+1)>=k  && i<=j){
            product=product-nums[i];
            i++;
        }
        
        count=count+j-i+1;
        j++;
    }
    return count; 

    }
};