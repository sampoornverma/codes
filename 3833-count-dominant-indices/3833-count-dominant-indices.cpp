class Solution {
public:
    int dominantIndices(vector<int>& nums) {
    if(nums.size()==1)return 0;
    int sum=0;
    int count1=0;

    for(int i=nums.size()-2;i>=0;i--){
        sum=sum+nums[i+1];
        
        if(nums[i]>sum/(nums.size()-i-1)){
            count1++;
        }
    }
    return count1;    
    }
};