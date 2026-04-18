class Solution {
public:
    int REV(int n){
        int ans=0;
        while(n!=0){
            int x=n%10;
            ans=ans*10+x;
            n=n/10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        return abs(n-REV(n));
    }   
};