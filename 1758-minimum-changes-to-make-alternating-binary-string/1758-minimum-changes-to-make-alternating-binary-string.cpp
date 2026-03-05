class Solution {
public:
    int v(char a , string s){
        
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=a){
                count++;
            }
            a = (a == '0') ? '1' : '0';
            
        }
        return count;
    }
    int minOperations(string s) {
        return min(v('0',s),v('1',s));
    }
};