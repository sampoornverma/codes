class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        set<string> st;

        if (n < k) return false;

        int i = 0;

        while (i <= n - k) {
            st.insert(s.substr(i, k));  // fix here
            i++;
        }

        int x = pow(2, k);

        return st.size() == x;
    }
};