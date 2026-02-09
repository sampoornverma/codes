class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> arr;
        stack<long long> st;

        int i = nums.size() - 1;
        st.push(nums[i]);
        i--;

        while (i >= 0) {
            long long top = st.top();

            if (top == nums[i]) {
                st.pop();
                long long d = top + nums[i];

                // ✅ Safe chain merge
                while (!st.empty() && st.top() == d) {
                    d += st.top();
                    st.pop();
                }

                st.push(d);
                i--;
            } else {
                st.push(nums[i]);
                i--;
            }
        }

        // Extract stack
        while (!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }
        return arr;
    }
};