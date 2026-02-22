class Solution {
public:
    int binaryGap(int n) {
    string s = "";
    while (n > 0) {
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    int maxi=0;
    int count=0;
    bool a=false;
    int b=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            a=true;
            maxi=max(maxi,count);
            count=0;
            b++;
        }
        if(s[i]=='0'  &&  a){
            count++;
        }
    }
    if(maxi==0 && b>1)return 1;
    if(maxi==0)return 0;
    return maxi +1;
    }

};