class Solution {
public:
    int maxDepth(string s) {
        int x=0;
        int maxi=0;
    for (char c:s){
        if(c=='(')x++;
        if(c==')')x--;
        maxi=max(maxi,x);
    }
    return maxi;  
    }
};