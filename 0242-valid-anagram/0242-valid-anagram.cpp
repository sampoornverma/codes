class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.size()!= t.size())return false;
    map<int,char> mp1;
    map<int,char> mp2;
    for(char c:s){
        mp1[c]++;
    }
    for(char c:t){
        mp2[c]++;
    }
    for(char c:s){
        if(mp1[c]!=mp2[c]){
            return false;
            break;
        }
    }
    return true;

    }
};