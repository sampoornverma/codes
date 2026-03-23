class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int a=nums[0];
        int b=0;
        int curr=nums[0];
        for(int i=1;i<n;i++){
           int noti = a;
           int take=nums[i]+b;
           curr=max(noti,take);
           b=a;
           a=curr;
        }
        return curr;
    }
};