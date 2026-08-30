class Solution {
public:
    int climbStairs(int n) {
        int a=1;
        int b=2;
        if(n<=2)return n;
        for(int i=2;i<n;i++){
            int x=a+b;
            a=b;
            b=x;
        }
        return b;

        
    }
};