class Solution {
public:
    bool checkDivisibility(int n) {
        int xg=n;
        int sum=0;
        int p=1;
        while(n!=0){
            int x=n%10;
            n=n/10;
            sum+=x;
            p *= x;
        }
        if(xg%(p+sum)==0)return true;
        else return false;
    }
};