class Solution {
public:
    vector<int> x={128,64,32,16,8,4,2,1};
    string f(char c){
        string s="";
        int x1=97+c-'a';
        int n=x.size();
        for(int i=0;i<n;i++){
            if(x1-x[i]>=0){
                s=s+'1';
                x1=x1-x[i];
            }else{
                s=s+'0';
            }
        }
        return s;

    }
    bool isPalindromic(string s) {
        int n=s.length();
        for(int i=0;i<n/2;i++){
           string g=f(s[i]) ;
           string p=f(s[n-i-1]);
           reverse(p.begin(),p.end());
           if(g!=p)return false;
        }
        if(n%2!=0){
            string g=f(s[n/2]) ;
           string p=g;
           reverse(p.begin(),p.end());
           if(g!=p)return false;
        }
        return true;
    }

};