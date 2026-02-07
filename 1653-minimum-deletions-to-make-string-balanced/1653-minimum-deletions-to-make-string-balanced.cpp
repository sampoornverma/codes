class Solution {
public:
    int minimumDeletions(string s) {
    if(s.size()==1)return 0;
    int n=-1;
    int m=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='b'){
            n=i;
            break;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='a'){
            m=i;
            break;
        }
    }
    if(n== -1 || m==-1)return 0;
    if(n>m)return 0;
    int count=0;
    for(int i=n;i<=m;i++){
    if(s[i]=='b')count++;   
    }
    return min((m-n+1)-count,count);
    }
};