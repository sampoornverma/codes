class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;

    int a=0;

    int b=1;
    int curr=1;
    
    for(int i=1;i<=n;i++){
        curr=a+b;
        b=a;
        a=curr;
    }
    return curr;
    }
};