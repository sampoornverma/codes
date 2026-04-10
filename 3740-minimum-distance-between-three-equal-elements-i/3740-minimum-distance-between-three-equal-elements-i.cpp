class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        // Step 1: since nums[i] <= n, we can safely use vector
        vector<vector<int>> arr(n + 1);

        // Step 2: store indices
        for(int i = 0; i < n; i++) {
            arr[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Step 3: check each value
        for(int i = 0; i <= n; i++) {
            auto &v = arr[i];
            if(v.size() >= 3) {
                for(int j = 0; j + 2 < v.size(); j++) {
                    int dist = 2 * (v[j+2] - v[j]);
                    ans = min(ans, dist);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};