class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            sum=sum+arr[i];
        }
        if(sum%2==1)return false;
        int k=sum/2;
          vector<vector<bool>> dp(n, vector<bool>(k+1,false));

    for(int i=0;i<n;i++)
        dp[i][0] = true;

    if(arr[0] <= k)
        dp[0][arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int target=1; target<=k; target++){

            bool notTake = dp[i-1][target];
            bool take = false;

            if(arr[i] <= target)
                take = dp[i-1][target-arr[i]];

            dp[i][target] = take || notTake;
        }
    }

    return dp[n-1][k];


    }
};