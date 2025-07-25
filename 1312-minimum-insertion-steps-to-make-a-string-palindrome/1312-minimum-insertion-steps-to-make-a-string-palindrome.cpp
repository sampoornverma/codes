class Solution {
public:
int f(string& i, string& j,int n,int m,vector<vector<int>> &dp){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m] != -1) return dp[n][m];
        if(i[n-1]==j[m-1])return dp[n][m]= 1+f(i,j,n-1,m-1,dp);
        else{
            return dp[n][m]= max(f(i,j,n-1,m,dp),f(i,j,n,m-1,dp));
        }
    }
    int minInsertions(string text1) {
        string text2 = text1;
    reverse(text2.begin(), text2.end());  // STL reverse instead of undefined reverseString
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int x= f(text1, text2, n, m, dp);
    return n-x;
    }
};