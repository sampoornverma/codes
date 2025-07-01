class Solution {

public:
    int f(string &s, string& t,int i,int j,vector<vector<int>> &dp){
    if(j<0) return i+1;
    if(i<0) return j+1;
    if(dp[i][j]!= -1 ) return dp[i][j];
    if(s[i]==t[j])return dp[i][j]=f(s,t,i-1,j-1,dp);
    else{
        return dp[i][j]=min(1+f(s,t,i-1,j,dp),min(1+f(s,t,i,j-1,dp),1+f(s,t,i-1,j-1,dp)));
    }
}
    int minDistance(string str1, string str2) {
        int n=str1.size();
int m=str2.size();
vector<vector<int>> dp(n,vector<int>(m,-1));
return f(str1,str2,n-1,m-1,dp);
    }
};