class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int a=nums[0];
        if(n==1)return a;
        int b=max(nums[0],nums[1]);
        if(n==2)return b;
        for(int i=2;i<n;i++){
            int x= max(nums[i]+a,b);
            a=b;
            b=x;
        }
        return b;
    }
};