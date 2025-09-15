class Solution {
public:
    int canBeTypedWords(string t, string b) {
    vector<int> c1(26,0);
    for(char c:b){
        c1[c-'a']=1;
    }
    int count=0;
    bool x=true;
    for(char c:t){
        if(c==' '){
            if(x)count++;
            x=true;
        }
        else if(c1[c-'a']==1){
            x=false;
        }
    }
    if(x)count++;
    return count;
    }
};