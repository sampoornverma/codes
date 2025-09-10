class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
    string a=goal;
    int i=goal.size()-1;
    while(a != s && i>=0){
    string x =goal.substr(0,i);
    string y="";
    if(i != goal.size())y=goal.substr(i,goal.size()-i);
    a=y+x;
    i--;
    }
    if(a==s){
        return true;
    }return false;

    }
};