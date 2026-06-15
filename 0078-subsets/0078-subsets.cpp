class Solution {
public:
    void f(vector<int>& nums,vector<int>& arr,vector<vector<int>>& ans,int i){
        if(i==nums.size()){
            ans.push_back(arr);
            return;
        }
        f(nums,arr,ans,i+1);
        arr.push_back(nums[i]);
        f(nums,arr,ans,i+1);
        arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        f(nums,arr,ans,0);
        return ans;
    }
};