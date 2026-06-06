class Solution {
public:
    bool consecutiveSetBits(int n) {
       bool prev=false;
       int count=0;
       bool curr=false;
       while(n>0){
        if((n) & 1) curr=true;
        n =n>>1;
        if(prev && curr)count++;
        prev= curr;
        curr=false;
       }
       if(count==1)return true;
       return false; 
    }
};