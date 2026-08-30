class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=-1e9;
        int mini=1e9;
        int maxii=-1;
        int n=nums.size();
        int minii=-1;
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi=max(maxi,nums[i]);
                maxii=i;
            }if(mini>nums[i]){
                mini=min(mini,nums[i]);
                minii=i;
            }
        }
        int a=0;
                int b=0;
        if(minii<maxii){
            a=minii+1+n-maxii;
            b=n-minii;
        }else{
             a=maxii+1+n-minii;
             b=n-maxii;
        }


        return min(max(minii,maxii)+1,min(a,b));
    }
};