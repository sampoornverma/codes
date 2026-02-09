class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;

        for (int x : nums) {
            long long cur = x;

            // Chain merging
            while (!st.empty() && st.top() == cur) {
                cur += st.top();
                st.pop();
            }

            st.push(cur);
        }

        // Convert stack to array
        vector<long long> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};