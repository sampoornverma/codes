class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini=1e5;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(abs(i-start)<mini)mini=abs(i-start);
            }
        }
        return mini;
    }
};