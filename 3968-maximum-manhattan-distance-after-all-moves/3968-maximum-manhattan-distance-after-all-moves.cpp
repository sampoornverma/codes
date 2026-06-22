class Solution {
public:
    int maxDistance(string moves) {
        int l=0;
        int d=0;
        int count=0;
        for( char c:moves){
            if(c=='L')l++;
            else if(c=='R')l--;
            else if(c=='D')d++;
            else if(c=='U')d--;
            else count++;
        }
         l=abs(l);
         d=abs(d);
        return count+l+d;
    }
};