class Solution {
public:
    string processStr(string s) {
        string a="";
        for(char c:s){
            if(c=='#'){
                if(a.size()==0)continue;
                a=a+a;}
            else if(c=='%'){if(a.size()==0)continue;reverse(a.begin(),a.end());}
            else if(c=='*'){if(a.size()==0)continue;a.pop_back();}
            else{
                a=a+c;
            }
        }
        return a;
    }
};