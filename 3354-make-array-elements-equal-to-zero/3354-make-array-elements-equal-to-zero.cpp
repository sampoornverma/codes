class Solution {
public:
    int countValidSelections(vector<int>& nums) {
    int a=0;
    for(int i=0;i<nums.size();i++){
        a=a+nums[i];
    } 
    int sum=0,count=0;
    
    for(int i=0;i<nums.size();i++){
    sum=sum+nums[i];
    if(nums[i]==0){
        if(sum==a-sum+1){
            count++;
        }
        if(sum+1==a-sum){
            count++;
        }
        if(sum==a-sum){
            count=count+2;
        }
    }
    }
    return count; 
    }
};