class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        
        int x=0;
        if(nums.size()==1)return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)x++;
        }
        int count=x;
      int n = nums.size();

for(int i=n-1;i>=n-x;i--){
    if(nums[i]==0) count--;
}
        return count;
        
    }
};