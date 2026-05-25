class Solution {
public:

    bool canJump(vector<int>& nums) {

        int n = nums.size();
        if(n==1)return true;
        vector<int> arr(n);
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            maxi--;
            if(maxi<0)return false;
            if(i==n-1){
                if(maxi>0)return true;
            }
            maxi=max(maxi,nums[i]);
            
        }
        return true;

        
    }
};