class Solution {
public:
    bool checkOnesSegment(string s) {
        bool a=false;
        int count=0;
        int n=s.size()-1;


        for(int i=0;i<s.size();i++){
            if(i+1<=n && s[i]=='0' && s[i+1]=='1' && a){
                count++;
                
            }else if(i+1<=n && s[i]=='1' && s[i+1]=='0' ){
                a=true;

            }
        }
        if(count>0)return false;
        return true;
    }
};