class Solution {
public:
    int v(char start , string s){
        char a=start;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=a){
                count++;
            }
            if(a=='0'){
                a='1';
            }else{
                a='0';
            }
            
        }
        return count;
    }
    int minOperations(string s) {
        return min(v('0',s),v('1',s));
    }
};