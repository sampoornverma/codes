class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0 && nums[i]== j*k)j++;
        }
        return j*k;
    }
};