class Solution {
public:
    bool judgeCircle(string m) {
     int a=0;
     int b=0;
     for(int i=0;i<m.size();i++){
        if(m[i]=='L')a++;
        if(m[i]=='R')a--;
        if(m[i]=='D')b++;
        if(m[i]=='U')b--;

     }
     if(a==0 && b==0)return true;
     return false;   
    }
};