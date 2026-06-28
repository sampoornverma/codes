class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1)arr[0]=1;
        int n=arr.size();
        if(n==1)return arr[0];
        int mini=0;
        int x=1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1])arr[i]=arr[i-1]+1;
        }
        return arr[n-1];
    }
};