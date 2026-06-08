class Solution {
public:

    int f(int i,int j,vector<vector<int>>& o,
          vector<vector<int>>& dp){

        if(i>=o.size() || j>=o[0].size())
            return 0;

        if(o[i][j]==1)
            return 0;

        if(i==o.size()-1 && j==o[0].size()-1)
            return 1;

        if(dp[i][j]!=-1)
            return dp[i][j];

        return dp[i][j] =
            f(i+1,j,o,dp) +
            f(i,j+1,o,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& o) {

        vector<vector<int>> dp(
            o.size(),
            vector<int>(o[0].size(),-1)
        );

        return f(0,0,o,dp);
    }
};