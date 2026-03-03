class Solution {
public:
    string rev(string k){
        string g="";
        for(int i=0;i<k.size();i++){
            if(k[i]=='0') g+='1';
            else g+='0';
        }
        reverse(g.begin(), g.end());
        return g;
    }

    string r(int n){
        if(n == 1) return "0";
        string prev = r(n-1);
        return prev + "1" + rev(prev);
    }

    char findKthBit(int n, int k) {
        string s = r(n);
        return s[k-1];
    }
};