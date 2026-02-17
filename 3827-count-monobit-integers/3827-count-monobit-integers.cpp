class Solution {
public:
    int countMonobit(int n) {
        //0 1 3 7 
        int count=1;
        if(n==0)return 1;
        int n1=1;
        int x=2;
        while(n1<=n){
            count++;
            n1 = n1+x;
            x=x*2;
        }
        return count;
    }
};