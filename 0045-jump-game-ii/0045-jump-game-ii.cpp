class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n,1000000);
        arr[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i] && i+j<n;j++){
                arr[i+j]=min(arr[i+j],arr[i]+1);
            }
        }
        return arr[n-1];
    }
};