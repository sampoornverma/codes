class Solution {
public:
    int c(vector<vector<int>>& o,int m,int n,vector<vector<int>>& dp,int x,int y,int count){
        if(x==m-1 && y==n-1) return 1;
        if(x>=m || y>=n) return 0;
        if(o[x][y]==1) return 0;
        if(dp[x][y]!= -1) return dp[x][y];
        int p=c(o,m,n,dp,x,y+1,count);
        int e=c(o,m,n,dp,x+1,y,count);
        dp[x][y]=p+ e;
         return dp[x][y];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m=o.size();
        int n=o[0].size();
        if (o[0][0] == 1 || o[m - 1][n - 1] == 1) return 0;

        vector<vector<int>> dp(m,vector<int>(n,-1));
        int count=0;
        return c(o,m,n,dp,0,0,count);
    }
};