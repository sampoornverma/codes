class Solution {
public:
    int c(int m,int n,vector<vector<int>>& dp,int x,int y,int count){
        if(x==m-1 && y==n-1) return 1;
        if(x>=m || y>=n) return 0;
        if(dp[x][y]!= -1) return dp[x][y];

        dp[x][y]=c(m,n,dp,x,y+1,count)+ c(m,n,dp,x+1,y,count);
         return dp[x][y];

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int count=0;
        return c(m,n,dp,0,0,count);
        
    }
};