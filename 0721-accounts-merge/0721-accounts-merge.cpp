class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int idx = 0;

        // Assign index for each email
        for (auto &acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                string email = acc[i];
                if (!emailToIndex.count(email)) {
                    emailToIndex[email] = idx++;
                    emailToName[email] = name;
                }
            }
        }

        DSU dsu(idx);

        // Union emails in the same account
        for (auto &acc : accounts) {
            int firstEmailIndex = emailToIndex[acc[1]];
            for (int i = 2; i < acc.size(); i++) {
                dsu.unite(firstEmailIndex, emailToIndex[acc[i]]);
            }
        }

        // Group by parent
        unordered_map<int, vector<string>> groups;
        for (auto &p : emailToIndex) {
            string email = p.first;
            int root = dsu.find(p.second);
            groups[root].push_back(email);
        }

        // Prepare result
        vector<vector<string>> result;
        for (auto &g : groups) {
            vector<string> emails = g.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[emails[0]]);
            result.push_back(emails);
        }

        return result;
    }
};