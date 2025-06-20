class Solution {
public:
    int f(vector<vector<int>>& o,vector<vector<int>>& dp,int n, int m,int x,int y){
        if(x==n-1 && y==m-1) return o[x][y];
        if(x>=n || y>= m) return 1e9;
        if(dp[x][y] != -1) return dp[x][y];
        dp[x][y]=min(o[x][y]+f(o,dp,n,m,x+1,y),
                     o[x][y]+f(o,dp,n,m,x,y+1)
        );
        return dp[x][y];
    }
    int minPathSum(vector<vector<int>>& o) {
        int n=o.size();
        int m=o[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(o,dp,n,m,0,0);
    }
};