class Solution {
public:
    int dp(int i,vector<int>& d,int n){
        if(i>n)return 0;
        if(d[i]!=0)return d[i];
        int one=0;
        if(i+1<=n)one= 1+dp(i+1,d,n);
        int two=0;
        if(i+2<=n)1+dp(i+2,d,n);
        return d[i]=one+two;
    }
    int climbStairs(int n) {
        vector<int> d(n+1,0);
        return dp(0,d,n);
    }
};