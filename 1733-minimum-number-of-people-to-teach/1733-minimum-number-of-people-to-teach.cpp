class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Store languages per user in a set for fast lookup
        vector<unordered_set<int>> know(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                know[i + 1].insert(lang);
            }
        }
        
        // Find problematic users
        unordered_set<int> problematic;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool ok = false;
            for (int lang : know[u]) {
                if (know[v].count(lang)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                problematic.insert(u);
                problematic.insert(v);
            }
        }
        
        if (problematic.empty()) return 0; // already fine
        
        // Try each language
        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for (int user : problematic) {
                if (!know[user].count(lang)) {
                    cnt++; // needs to be taught
                }
            }
            ans = min(ans, cnt);
        }
        
        return ans;
    }
};
