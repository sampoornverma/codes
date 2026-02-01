class Solution {
public:
    int minimumCost(vector<int>& nums) {
    int x=nums[0];
    sort(nums.begin(),nums.end());
    bool c=true;
    int s=0;
    if(nums[0]==x && c){
        s=s+x;
        c=false;
        }
        if(nums[0]==x && c){
        s=s+x;
        c=false;
        }

    }
};