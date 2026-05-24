class Solution {
public:
    int passwordStrength(string s) {
        int n=s.size();
        int ans=0;
        unordered_set<char> st;
        for(int i=0;i<n;i++){
            if(st.find(s[i]) != st.end()) continue;
            st.insert(s[i]);
            if(s[i]-'a'>=0 && s[i]-'a'<=25)ans=ans+1;
            if(s[i]-'A'>=0 && s[i]-'A'<=25)ans=ans+2;
            if(s[i]-'0'>=0 && s[i]-'0'<=9)ans=ans+3;
            if(s[i]=='!' || s[i]=='@' || s[i]=='#' || s[i]=='$')ans=ans+5;
        }
        return ans;
    }
};