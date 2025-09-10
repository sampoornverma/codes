class Solution {
public:
    bool checkPerfectNumber(int num) {
        int count=0;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){count=count+i;
        if(num/i != i)count=count+num/i;}
    }
    return count+1==num;  
    }
};