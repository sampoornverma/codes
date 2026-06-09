class Solution {
public:
    int count(string s){
        int count=0;
        for(char x:s){
            if(x=='1')count++;
        }
        return count;
    }
    int f(int i, vector<string>& strs, int m, int n,vector<vector<vector<int>>> &dp){

    if(i == strs.size())

        return 0;
    if(dp[i][n][m]!= -1)return dp[i][n][m];
    int ones = count(strs[i]);

    int zeros = strs[i].size() - ones;

    int notTake = f(i+1, strs, m, n,dp);

    int take = 0;

    if(m >= zeros && n >= ones)

        take = 1 + f(i+1,

                     strs,

                     m-zeros,

                     n-ones,dp);

    return dp[i][n][m]= max(take, notTake);

}
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(n+1,vector<int>(m+1,-1)));

        return f(0,strs,m,n,dp);
    }
};