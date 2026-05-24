class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        int count=0;
        int original=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]==original)count++;
            else if(nums[i]!=original){
                original=nums[i];
                count=1;
            }
            if(count<=k)ans.push_back(nums[i]);
        }
        return ans;
    }
};