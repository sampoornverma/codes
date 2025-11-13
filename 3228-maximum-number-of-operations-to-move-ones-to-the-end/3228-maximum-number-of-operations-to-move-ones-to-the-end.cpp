class Solution {
public:
    int maxOperations(string s) {
    string a=s;
    reverse(a.begin(),a.end());
    bool z=true;
    int x=0;
    int t=0;
    for(char c:a){
        if(c=='1'){
            t=t+x;
            z=true;
        }
        if(c=='0' && z){
            x++;
            z=false;
        }
    }
    return t;

    }
};