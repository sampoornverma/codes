class Solution {
public:
    bool ob(int n,int m,vector<vector<int>>& o){
        return o[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m=o.size();
        int n=o[0].size();
        if(  n>0 && m>0 && o[m-1][n-1]==1)return 0;
      vector<vector<int>> dp(m,vector<int>(n,0));
       dp[0][0]=1;
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(ob(i,j,o))continue;
            if(i==0 && j==0)continue;
            int up=0;
            if(j-1>=0 && !ob(i,j-1,o))up=dp[j-1][i];
            int left=0;
            if(i-1>=0 && !ob(i-1,j,o))left=dp[j][i-1];
            dp[j][i]=up+left;
        }
       }
       return dp[m-1][n-1];   
    }
};