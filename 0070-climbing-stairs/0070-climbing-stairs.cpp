class Solution {
public:
    // int dp(int i, vector<int>& d, int n){
    //     if(i == 0) return 1;   
    //     if(i < 0) return 0;

    //     if(d[i] != -1) return d[i];

    //     int one = dp(i-1, d, n);
    //     int two = dp(i-2, d, n);

    //     return d[i] = one + two;
    // }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
};