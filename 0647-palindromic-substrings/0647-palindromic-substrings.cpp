class Solution {
public:
    bool c(string s){
        string a = s;
        reverse(a.begin(), a.end());
        return a == s;
    }

    int countSubstrings(string s) {
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                string ans = s.substr(i, j - i + 1);
                if(c(ans)) count++;
            }
        }
        return count;
    }
};