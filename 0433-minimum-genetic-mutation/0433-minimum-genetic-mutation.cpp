class Solution {
public:
    int minMutation(string s, string e, vector<string>& bank) {

        unordered_set<string> st;
        for (auto &it : bank) {
            st.insert(it);
        }

        if (st.find(e) == st.end()) return -1;

        queue<pair<string, int>> q;
        q.push({s, 0});

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            string curr = it.first;
            int steps = it.second;

            if (curr == e) return steps;

            for (int i = 0; i < curr.size(); i++) {

                char original = curr[i];

                for (char g : genes) {

                    curr[i] = g;

                    if (st.find(curr) != st.end()) {
                        st.erase(curr);
                        q.push({curr, steps + 1});
                    }
                }

                curr[i] = original;
            }
        }

        return -1;
    }
};