class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
    char x=l[0];
    sort(l.begin(),l.end());
    for(int i=0;i<l.size();i++){
        if(l[i]>t)return l[i];
    }
    return  x;
    }
};