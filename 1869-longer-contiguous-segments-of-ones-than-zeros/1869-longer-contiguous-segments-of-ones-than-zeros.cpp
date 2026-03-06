class Solution {
public:
    bool checkZeroOnes(string s) {
        int n=s.size();
        int i=0;
        int maxzeros=0;
        int maxones=1;
        while(i<n){
            int start=i;
            int curr=s[i];
            while(i<n && s[i]==curr){
                i++;
            }
            int len=i-start;
            if(curr=='1'){
                maxones=max(maxones,len);
            }else{
                maxzeros=max(maxzeros,len);
            }
        }
        return maxones>maxzeros;
    }
};