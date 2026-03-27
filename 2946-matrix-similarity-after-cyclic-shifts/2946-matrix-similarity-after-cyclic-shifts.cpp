class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> arr=mat;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            rotate(arr[i],k);
            if(mat[i]!= arr[i])return false;
        }
        return true;
    }
};