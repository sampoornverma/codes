class Solution {
public:
    int scoreDifference(vector<int>& nums) {
    int a=0;
    int b=0;
    int x=5;
    int c=1;
    for(int i=0;i<nums.size();i++){
        if(i==x ){
            x=x+6;
            int temp=a;
            a=b;
            b=temp;
            c=c*-1;
        }
         if(nums[i]%2==1){
            
            int temp=a;
            a=b;
            b=temp;
            c=c*-1;
        }
        a=a+nums[i];
    }
    return c*(a-b);  
    }
};