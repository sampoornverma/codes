class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n), right(n);

        left[0] = arr[0];
        for(int i = 1; i < n; i++) {
            left[i] = max(arr[i], left[i-1] + arr[i]);
        }

        right[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            right[i] = max(arr[i], right[i+1] + arr[i]);
        }

        int ans = *max_element(left.begin(), left.end());

        for(int i = 1; i < n-1; i++) {
            ans = max(ans, left[i-1] + right[i+1]);
        }

        return ans;
    }
};