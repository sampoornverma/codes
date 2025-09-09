class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp1, mp2;  // two maps for both directions
        int i = 0;
        for (char c : s) {
            if (mp1.find(c) == mp1.end()) {
                mp1[c] = t[i];
            } else {
                if (mp1[c] != t[i]) return false;
            }

            if (mp2.find(t[i]) == mp2.end()) {
                mp2[t[i]] = c;
            } else {
                if (mp2[t[i]] != c) return false;
            }
            i++;
        }
        return true;    
    }
};