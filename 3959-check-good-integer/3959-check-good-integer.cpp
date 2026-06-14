class Solution {
public:
    bool checkGoodInteger(int n) {
        int total=0;
        int square=0;
        while(n>0){
            int l=n%10;
            total=total+l;
            square=square+l*l;
            n=n/10;
        }
        return square-total>=50;
    }
};