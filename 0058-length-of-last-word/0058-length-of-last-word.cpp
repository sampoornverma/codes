class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int count=0;
        bool x;
        if(s[n-1]==' ')x=true;
        for(int i=n-1;i>=0;i--){
            if(!x && s[i]==' ')break;
            if(x && s[i]==' '){continue;}
            else{count++; x=false;}
            
            }
        return count;
    }
};