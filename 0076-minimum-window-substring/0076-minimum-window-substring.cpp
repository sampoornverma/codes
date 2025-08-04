class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        map<char, int> mp;
        for (char c : t) mp[c]++;

        int required = t.size();
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int l1 = 0, r1 = 0;
        
        while (r < s.size()) {
            if (mp[s[r]] > 0) required--;
            mp[s[r]]--;
            r++;

            while (required == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    l1 = l;
                    r1 = r;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) required++;
                l++;
            }
        }

        string g;
        for (int k = l1; k < r1 && k < s.size(); k++) {
            g += s[k];
        }
        return minLen == INT_MAX ? "" : g;
    }
};