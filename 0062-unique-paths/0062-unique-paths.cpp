class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int>(n,0));
       dp[0][0]=1;
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(i==0 && j==0)continue;
            int up=0;
            if(j-1>=0)up=dp[j-1][i];
            int left=0;
            if(i-1>=0)left=dp[j][i-1];
            dp[j][i]=up+left;
        }
       }
       return dp[m-1][n-1]; 
    }
};