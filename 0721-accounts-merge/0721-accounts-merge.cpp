class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int node) {
            if (parent[node] == node)
                return node;

            return parent[node] = find(parent[node]);
        }

        void unite(int u, int v) {
            int parentU = find(u);
            int parentV = find(v);

            if (parentU == parentV)
                return;

            if (rank[parentU] < rank[parentV]) {
                parent[parentU] = parentV;
            }
            else if (rank[parentU] > rank[parentV]) {
                parent[parentV] = parentU;
            }
            else {
                parent[parentV] = parentU;
                rank[parentU]++;
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DSU dsu(n);

        // Step 1: Map every email to the first account
        // in which it appears
        unordered_map<string, int> emailToAccount;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                } else {
                    dsu.unite(i, emailToAccount[email]);
                }
            }
        }

        vector<vector<string>> mergedEmails(n);

        for (auto& it : emailToAccount) {
            string email = it.first;
            int account = it.second;

            int root = dsu.find(account);

            mergedEmails[root].push_back(email);
        }

        // Step 3: Build the answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedEmails[i].empty())
                continue;

            sort(mergedEmails[i].begin(), mergedEmails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (string& email : mergedEmails[i]) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};