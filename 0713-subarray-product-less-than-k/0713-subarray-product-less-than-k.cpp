class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            long long count=1;
             for(int j=i;j<n;j++){
                count=(count)*nums[j];
                if(count>=k)break;
                sum++;  
            }
        }
        return sum;
    }
};