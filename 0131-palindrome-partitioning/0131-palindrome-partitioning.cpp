class Solution {
public:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    void helper(string s, int i, vector<string>&path, vector<vector<string>>&ans) {
        if (i == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int end = i; end < s.size(); end++) {
            string sub = s.substr(i, end-i+1);
            if (isPalindrome(sub)) {
                path.push_back(sub);
                helper(s, end + 1, path,ans);
                path.pop_back();
                
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        helper(s,0,path,ans);
        return ans;
    }
};