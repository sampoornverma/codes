class Solution {
public:
    int numOfStrings(vector<string>& patterns, string s) {
       set<string> st;
       int n=s.size();
       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            st.insert(s.substr(i,j - i + 1));
        }
       } 
       int count=0;
       for(int i=0;i<patterns.size();i++){
        if(st.find(patterns[i])!=st.end())count++;
       }
       return count;
    }
};