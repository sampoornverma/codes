class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        vector<int> arr1(n, -1); // previous smaller
        vector<int> arr(n, n);   // next smaller

        stack<int> st;
        stack<int> st1;

        // Next smaller element
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }

            if(!st.empty()) {
                arr[i] = st.top();
            }

            st.push(i);
        }

        // Previous smaller element
        for(int i = 0; i < n; i++) {
            while(!st1.empty() && h[st1.top()] >= h[i]) {
                st1.pop();
            }

            if(!st1.empty()) {
                arr1[i] = st1.top();
            }

            st1.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int width = arr[i] - arr1[i] - 1;
            int area = width * h[i];

            ans = max(ans, area);
        }

        return ans;
    }
};