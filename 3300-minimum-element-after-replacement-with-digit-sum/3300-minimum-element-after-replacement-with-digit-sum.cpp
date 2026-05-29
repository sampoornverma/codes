class Solution {
public:
    int sum(int a){
        int count=0;
        while(a>0){
            count=count+a%10;
            a=a/10;
        }
        return count;
    }
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini=100000;
        for(int i=0;i<n;i++){
            mini=min(mini,sum(nums[i]));
        }
        return mini;
    }
};